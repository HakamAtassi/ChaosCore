
package ChaosCore

import scala.meta._
import java.nio.file.{Files, Paths}
import java.io.{BufferedWriter, FileWriter, IOException}
import scala.collection.mutable



object generate_sv_interfaces{    // convert bundles, params and enums to verilog

    // (interface name -> converted contents)
    val sv_interfaces = mutable.Map[String, Array[String]]()

    // dump sv_interfaces to file
    def write_structs(bundles: Map[String, Array[String]], fileName: String): Unit = {
        val filePath = fileName

        var writer: BufferedWriter = null
        writer = new BufferedWriter(new FileWriter(filePath))
            
        for ((structName, declarations) <- bundles) {
            writer.write(s"interface $structName;\n")
            for (declaration <- declarations) {
                writer.write(s"    $declaration")
            }
            writer.write(s"endinterface;\n\n")
        }

        println(s"Structs have been written to $filePath")
        if (writer != null) {
                writer.close()
        }
    }

    val isVecTraverser = new Traverser {
        override def apply(tree: Tree): Unit = tree match {
            case Defn.Val(_, pats, _, rhs) => 
            // Check if the RHS contains a Vec
            if (rhs.syntax.contains("Vec")) {
                // Iterate through the patterns (names) in the definition
                pats.foreach {
                case Pat.Var(termName) =>
                    println(s"The variable '${termName.value}' contains a Vec in its RHS.")
                case _ => // Handle other patterns if necessary
                }
            }

            case node => super.apply(node)
        }
    }

    def findArgClause(tree: Tree): Term.ArgClause = {
        var found_clause: Option[Term.ArgClause] = None

        object argClauseTraverser extends Traverser {
            override def apply(tree: Tree): Unit = tree match {
            case clause @ Term.ArgClause(_, _) => 
                found_clause = Some(clause)
            case _ => super.apply(tree)
            }
        }
        argClauseTraverser(tree)
        found_clause.getOrElse(throw new NoSuchElementException("Term.ArgClause not found"))
    }







    def chisel_to_sv(line: Defn.Val, bundle_names:Array[String]): String = {

        def containsType(typeName: String): Boolean = {
            line.rhs.collect {
            case Term.Apply(fun, _) if fun.syntax.contains(typeName) => true
            }.nonEmpty
        }

        def get_vector_width(argClause: Term.ArgClause):String = {

            argClause.values(0).toString
        }


        def get_vector_type(argClause: Term.ArgClause): String = {
            // check for node of Term.Apply or Term.New. 
            // When found, return get Term.Name.
            // return Term.Name as a string

            argClause.values.collectFirst {
                //case Term.Apply(Term.Select(_, Term.Name(name)), _) => name // this doesnt 
                case Term.Apply(Term.Name(name), _) => name
                case Term.New(Init(Type.Name(name), _, _)) => name  // this works
            }.getOrElse("unknown")
        }

        def get_bits(argClause: Term.ArgClause): String = {
            argClause.values.collectFirst {
                //case Term.Select(Lit.Int()) =>
                //case Term.Select(Term.Name()) => 
                case Term.Select(Term.Name(qual), _) => qual
                case Lit.Int(value) => value.toString
                case Term.Name(name) => name


            }.getOrElse("1")
        }




        // convert chisel to sv

        // "int" typehint?
        // localparam id = value.replace("$log2Ceil", "$clog2")

        val rhs_term_name = line.rhs match {
            case Term.Name(name) => name
            case Term.Select(_, Term.Name(name)) => name
            case Term.Apply(Term.Name(name), _) => name
            case Term.Apply(Term.Select(_, Term.Name(name)), _) => name
            case Term.New(Init(Type.Name(name), _, _)) => 
            name
            case _ => "unknown"
        }
        //println(s"$line \t\t\t\t\t $rhs_term_name")
        

        val identifier = line.pats(0)
        var bits = get_bits(findArgClause(line))
        //println(bits)

        val is_Vec          = containsType("Vec")

        val is_localparam      = line.decltpe.getOrElse(0) != 0

        var Vec_width = ""
        var Vec_type  = ""


        
        if(is_Vec){
            val vec_clause = findArgClause(line)
            Vec_width = get_vector_width(vec_clause)
            Vec_type = get_vector_type(vec_clause)
        }else{
            //println(rhs_term_name)
        }

        val optional_brackets = if (bundle_names.contains(rhs_term_name) || bundle_names.contains(Vec_type)) "()" else ""
        


        // get bit width of underlying type, vector or not
        val is_UInt         =  containsType("UInt")
        val is_SInt         =  containsType("SInt")
        val is_Bool         =  containsType("Bool")


        
        var decleration = s""
        if(is_localparam){
            decleration = s"localparam ${identifier} = ${line.rhs.toString};\n".replace("log2Ceil", "$clog2")
            //println(decleration)
        } else if(is_Vec){
            //declaration = s"$type"
            if(is_UInt || is_SInt || is_Bool){  // primitive vec
                decleration = s"logic[$bits-1:0] $identifier[$Vec_width];\n";
            }else{
                decleration = s"$Vec_type $identifier[$Vec_width]$optional_brackets;\n";
            }
        }else{
            if(is_UInt || is_SInt || is_Bool){  // primitive
                decleration = s"logic[$bits-1:0] $identifier;\n";
            }else{
                decleration = s"$rhs_term_name $identifier$optional_brackets;\n";
            }

            //println(decleration)
        }


        //println(decleration)


        // standard types
        // logic[??-1:??] id;
        // standard vecs
        // logic[??-1:??] id[];

        // user defined types
        // type id();
        // user defined vec
        // type id[count]();


        decleration
    }

    def to_interface(bundle: Defn.Class, bundle_names: Array[String]): Map[String, Array[String]] = {
        // collection declerations and convert to sv
        val class_name = bundle.name.value

        val declerations = bundle.collect {    // decleration lines
            case cls @ Defn.Val(pats, decltpe, rhs, argClause) =>
            cls
        }
        
        //val sv_declerations: Array[String] = declerations.map(chisel_to_sv).toArray
        val sv_declerations: Array[String] = declerations.map(decl => chisel_to_sv(decl, bundle_names)).toArray

        Map(class_name -> sv_declerations)
    }

    def convert(tree: Tree):Map[String, Array[String]] = {
        val bundles = tree.collect {    // collect bundles
            case cls @ Defn.Class(_, name, _, _, template) if template.inits.exists(_.tpe.syntax == "Bundle") =>
            cls
        }

        val bundle_names = tree.collect{
            case cls @ Defn.Class(_, name, _, _, template) if template.inits.exists(_.tpe.syntax == "Bundle") =>
            name.toString
        }.toArray

        // Map over each bundle and convert from Chisel to SV, passing both the bundle and the array of all bundle names
        bundles.map(bundle => to_interface(bundle, bundle_names)).foldLeft(Map.empty[String, Array[String]])(_ ++ _)
    }




    def apply(paramtersDir:String, bundlesDir:String):Unit = {

        val bundles        = new String(Files.readAllBytes(Paths.get(bundlesDir)))
        val bundleTree     = bundles.parse[Source].get

        val converted_interfaces = convert(bundleTree)
        write_structs(converted_interfaces, "../verilog/typedefs.sv")

    }
}

