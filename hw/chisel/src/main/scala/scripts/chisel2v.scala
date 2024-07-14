
package ChaosCore

import scala.meta._
import java.nio.file.{Files, Paths}
import java.io.{BufferedWriter, FileWriter, IOException}




object chisel2v{    // convert bundles, params and enums to verilog

    def apply(paramtersDir:String, bundlesDir:String):Unit = {

        var paramterArray = Array[String]()

        var bundleMap   = Map[String, Array[String]]()


        val parameterTraverser = new Traverser { // get parameters and convert
            override def apply(tree: Tree): Unit = tree match {

                case Term.Param(mods, name, decltpe, default) =>  // print name and decltpe
                val parameter = name
                val tpe = decltpe.getOrElse(Int)
                val a = default.getOrElse(0)
                val paramterString = s"parameter $parameter=$a;"
                paramterArray +:= paramterString
                case node => super.apply(node)
            }
        }


        var current_declerations = Array[String]()

        val declerationTraverser = new Traverser { // get decleration

            override def apply(tree: Tree): Unit = {

                tree match {    
                    case Defn.Val(pos, pats, decltpe, rhs) =>  // print name and decltpe

                    val decleration_identifier = pats(0).toString
                    //println(rhs.structure)

                    //println(decleration_identifier)
                    //println(rhs.children.structure)
                    //println(rhs.children(1).children.structure)

                    val decleration_type = rhs.children(0).toString
                    var decleration_width = ""//rhs.children(1)

                    var decleration = ""


                    //println(rhs)
                    //rhsTraverser(rhs.children(0))



                    if(decleration_type == "Bool"){
                        decleration_width = "1"
                        decleration = s"logic $decleration_identifier;\n";
                    }else if(decleration_type== "UInt" || decleration_type == "SInt"){
                        //println(rhs.children(1).children(0).children(0).structure)
                        decleration_width = rhs.children(1).children(0).children(0).toString
                        //println(decleration_width)
                        decleration = s"logic [$decleration_width-1:0] $decleration_identifier;\n";
                        //print(decleration)
                    }else if(decleration_type == "Vec"){

                        val vec_decleration_width = rhs.children(1).children(0).toString()
                        val vec_decleration_type = rhs.children(1).children(1).toString()
                        //println(vec_decleration_type)
                        //println(vec_decleration_width)

                        if(decleration_type == "Bool"){
                            decleration_width = "1"
                            decleration = s"logic $decleration_identifier;\n";
                        }else if(decleration_type== "UInt" || decleration_type == "SInt"){
                            decleration_width = rhs.children(1).children(0).children(0).toString
                            decleration = s"logic [$decleration_width-1:0] $decleration_identifier;\n";
                        }

                        decleration = "ERROR\n"
                        //println(rhs.children(1).toString)
                    }else{    // user defined
                        decleration = s"$decleration_type $decleration_identifier;\n";
                        //println(decleration)
                    }



                    current_declerations :+= decleration





                    //println(s"$a $test")
                    case node => super.apply(node)
                }
            }
        }



        val bundleTraverser = new Traverser {   // FIXME: 
            override def apply(tree: Tree): Unit = tree match {
                case Defn.Class(pos, name, tparamClause, ctor, templ) =>
                //println(s"// // $name")
                //println(s"$templ")

                current_declerations = Array[String]()
                declerationTraverser(tree)


                bundleMap = bundleMap.updated(name.toString, current_declerations)


                // You are now in the bundle. traverse until all its elements are found
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
                    writer.write(s"$parameter;\n")
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
                    writer.write(s"typedef struct {\n")
                    for (declaration <- declarations) {
                        writer.write(s"    $declaration")
                    }
                    writer.write(s"} $structName;\n\n")
                }

                println(s"Structs have been written to $filePath")
                if (writer != null) {
                        writer.close()
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


        writeParameters(paramterArray, "../verilog/Parametrs.sv")
        writeStructs(bundleMap, "../verilog/typedef.sv")




    }

}

