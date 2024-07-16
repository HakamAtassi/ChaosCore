
package ChaosCore

import scala.meta._
import java.nio.file.{Files, Paths}
import java.io.{BufferedWriter, FileWriter, IOException}




object chisel2v{    // convert bundles, params and enums to verilog

    def apply(paramtersDir:String, bundlesDir:String):Unit = {

        var paramterArray = Array[String]()

        var bundleMap   = Map[String, Array[String]]()
        var enumMap     = Map[String, Array[String]]()



    val parameterTraverser = new Traverser { 
    // get parameters and convert
    override def apply(tree: Tree): Unit = tree match {
        case Term.Param(mods, name, decltpe, default) =>  // print name and decltpe
        val parameter = name
        val tpe = decltpe.getOrElse(t"Int")
        val a = default.getOrElse(q"0")
        var paramterString = s"parameter $parameter=$a;"
        
        // Replace "true" with "1", "false" with "0", and remove ".U"
        paramterString = paramterString
            .replace("true", "1")
            .replace("false", "0")
            .replace(".U", "")
        
        // Replace "hxxxxxxxx" with 'hxxxx
        paramterString = paramterString.replaceAll("\"h([0-9A-Fa-f]+)\"", "'h$1")
        paramterArray :+= paramterString

        case Defn.Val(mods, pats, decltpe, rhs) => 
        // Extract term name and rhs
        pats.foreach {
            case Pat.Var(termName) =>
            var paramterString = s"localparam ${termName.value}=${rhs.syntax};"
            paramterArray :+= paramterString.replace("log2Ceil", "$clog2")
        }

        case node => super.apply(node)
    }
    }

        var current_declerations = Array[String]()

        val declerationTraverser = new Traverser { // get decleration

            override def apply(tree: Tree): Unit = {

                tree match {    
                    case Defn.Val(pos, pats, decltpe, rhs) =>  // print name and decltpe

                    val decleration_identifier = pats(0).toString
                    val has_localparam_typehint = decltpe.toString
                    //println(rhs.structure)

                    //println(decleration_identifier)
                    //println(rhs.children.structure)
                    //println(rhs.children(1).children.structure)

                    val decleration_type = rhs.children(0).toString.replace("(parameters)", ("")).replace("new ", "")
                    var decleration_width = ""//rhs.children(1)

                    var decleration = ""

                    


                    //println(rhs)
                    //rhsTraverser(rhs.children(0))


                    if (has_localparam_typehint == "Some(Int)"){
                        val param_value = rhs.toString
                        decleration = s"localparam $decleration_identifier = $param_value;\n"
                    }else if(decleration_type == "Bool"){
                        decleration_width = "1"
                        decleration = s"logic $decleration_identifier;\n";
                    }else if(decleration_type== "UInt" || decleration_type == "SInt"){
                        decleration_width = rhs.children(1).children(0).children(0).toString
                        decleration = s"logic [$decleration_width-1:0] $decleration_identifier;\n";
                    }else if(decleration_type == "Vec"){
                        val vec_decleration_width = rhs.children(1).children(0).toString()
                        val vec_decleration_type = rhs.children(1).children(1).toString()

                        //println(vec_decleration_type)
                        //println(vec_decleration_width)

                        decleration = "ERROR\n"

                        if(vec_decleration_type == "Bool()"){
                            decleration = s"logic $decleration_identifier[$vec_decleration_width];\n";
                        }else if(vec_decleration_type== "UInt" || vec_decleration_type == "SInt"){
                            decleration_width = rhs.children(1).children(0).children(0).toString
                            decleration = s"logic [$decleration_width-1:0] $decleration_identifier[$vec_decleration_width];\n";
                        }else{
                            //decleration_width = rhs.children(1).children(0).toString
                            //decleration_width = rhs.children(1).toString
                            //decleration = s"logic [$decleration_width-1:0] $decleration_identifier[$vec_decleration_width];\n";
                            //println(decleration_width)
                        }

                    }else{    // user defined
                        decleration = s"$decleration_type $decleration_identifier;\n"
                        //println(decleration)
                    }



                    current_declerations :+= decleration.replace("log2Ceil", "$clog2")





                    //println(s"$a $test")
                    case node => super.apply(node)
                }
            }
        }



        val bundleTraverser = new Traverser {
            override def apply(tree: Tree): Unit = tree match {
                case Defn.Class.After_4_6_0(pos, name, tparamClause, ctor, templ) =>
                //println(s"// // $name")
                //println(s"$templ")

                current_declerations = Array[String]()
                declerationTraverser(tree)
                //println(tree.toString)

                bundleMap = bundleMap.updated(name.toString, current_declerations)

                case node => super.apply(node)
            }
        }


  val enumTraverser = new Traverser {
    override def apply(tree: Tree): Unit = tree match {
      case Defn.Object(_, name, templ) =>
        //println(s"Processing object: $name")
        // Traverse the template to find all Defn.Val elements
        val verilogLines = templ.stats.collect {
          case valDef: Defn.Val =>
            // Extract identifiers and their corresponding values
            val identifiersWithValues = valDef.pats.collect {
              case Pat.Var(Term.Name(id)) =>

                val value = valDef.rhs match {
                  case Term.Apply.After_4_6_0(_, args) if args.nonEmpty =>
                    val binString = valDef.rhs match {
                        case Term.Apply(_, List(Term.Select(Lit.String(binaryString), Term.Name("U")))) =>
                            s"'$binaryString"
                        case _ =>
                            println("No match found")
                    }
                    s"$id = ${binString}"

                  case _ => id
                }
                value
            }
            identifiersWithValues
        }.flatten.toArray

        // Add to the enumMap
        enumMap += (name.value -> verilogLines)

      case node => super.apply(node)
    }
  }





        object writeParameters {
            def apply(parameterList: Array[String], fileName:String): Unit = {
                // Define the file path where you want to write the parameters
                val filePath = fileName

                // Use a BufferedWriter to write to the file
                var writer: BufferedWriter = null
                writer = new BufferedWriter(new FileWriter(filePath))
                for (parameter <- parameterList) {
                    writer.write(s"$parameter\n")
                }
                println(s"Parameters have been written to $filePath")
                if (writer != null) {
                        writer.close()
                }
            }
        }


        object writeStructs {
            def apply(bundles: Map[String, Array[String]], fileName: String): Unit = {
                val filePath = fileName

                // Use a BufferedWriter to write to the file
                var writer: BufferedWriter = null
                writer = new BufferedWriter(new FileWriter(filePath))
                
                for ((structName, declarations) <- bundles) {
                    writer.write(s"interface $structName;\n")
                    for (declaration <- declarations) {
                        writer.write(s"    $declaration")
                    }
                    //writer.write(s"} $structName;\n\n")
                    writer.write(s"endinterface;\n\n")
                }

                println(s"Structs have been written to $filePath")
                if (writer != null) {
                        writer.close()
                }
            }
        }


    def writeEnums(enumMap: Map[String, Array[String]], fileName: String): Unit = {
    var writer: BufferedWriter = null
    try {
        writer = new BufferedWriter(new FileWriter(fileName))
        enumMap.foreach { case (bundleName, verilogLines) =>
        writer.write(s"typedef enum logic {\n")
        val formattedLines = verilogLines.mkString(",\n  ")
        writer.write(s"  $formattedLines\n")
        writer.write(s"} $bundleName;\n\n")
        }
        println(s"Enums have been written to $fileName")
    } catch {
        case e: IOException => e.printStackTrace()
    } finally {
        if (writer != null) {
        try {
            writer.close()
        } catch {
            case e: IOException => e.printStackTrace()
        }
        }
    }
    }




        //val parametersDir  = Paths.get("src/main/scala/Parameters.txt")
        //val bundlesDir     = Paths.get("src/main/scala/Bundles.txt")


        val parameters     = new String(Files.readAllBytes(Paths.get(paramtersDir)))
        val bundles        = new String(Files.readAllBytes(Paths.get(bundlesDir)))

        val parametersTree  = parameters.parse[Source].get
        val bundleTree      = bundles.parse[Source].get

        parameterTraverser(parametersTree)
        bundleTraverser(bundleTree)
        enumTraverser(bundleTree)




        writeParameters(paramterArray, "../verilog/parameters.sv")
        writeStructs(bundleMap, "../verilog/typedef.sv")
        writeEnums(enumMap, "../verilog/enums.sv")




    }

}

