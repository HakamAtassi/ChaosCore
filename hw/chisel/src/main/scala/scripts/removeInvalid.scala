package ChaosCore

import java.io.{File, PrintWriter}
import scala.io.Source

object removeYosysInvalid {

  def apply(directory: String): Unit = {
    // Get the list of all Verilog files in the directory
    val verilogFiles = getListOfVerilogFiles(new File(directory))

    // Process each Verilog file
    verilogFiles.foreach { file =>
      // Read the contents of the file
      val source = Source.fromFile(file)
      val fileContents = try source.mkString finally source.close()

      // Replace all instances of "hasBeenResetReg = 1'bx" with "hasBeenResetReg = 1'b0"
      val updatedContents = fileContents.replace("hasBeenResetReg = 1'bx;", "hasBeenResetReg = 1'b0;")

      // Write the updated contents back to the file
      val writer = new PrintWriter(file)
      try writer.write(updatedContents) finally writer.close()
    }
  }


  def getListOfVerilogFiles(dir: File): List[File] = {
    if (dir.exists && dir.isDirectory) {
      dir.listFiles.filter(_.isFile).toList.filter(file => file.getName.endsWith(".v") || file.getName.endsWith(".sv"))
    } else {
      List[File]()
    }
  }


}
