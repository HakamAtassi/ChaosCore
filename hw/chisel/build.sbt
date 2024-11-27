//// See README.md for license details.

//ThisBuild / scalaVersion     := "2.13.14"
//ThisBuild / version          := "0.1.0"
//ThisBuild / organization     := "%ORGANIZATION%"

//val chiselVersion = "6.4.0"

//lazy val root = (project in file("."))
  //.settings(
    //name := "ChaosCore",
    //libraryDependencies ++= Seq(
      //"org.chipsalliance" %% "chisel" % chiselVersion,
      //"org.scalatest" %% "scalatest" % "3.2.16" % "test",
      //"org.scalameta" %% "scalameta" % "4.9.8"
    //),
    //scalacOptions ++= Seq(
      //"-language:reflectiveCalls",
      //"-deprecation",
      //"-feature",
      //"-Xcheckinit",
      //"-Ymacro-annotations",
    //),
    //addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  //)

// See README.md for license details.

ThisBuild / scalaVersion     := "2.12.8"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "%ORGANIZATION%"



val chiselVersion = "3.5.4"

lazy val root = (project in file("."))
  .settings(
    name := "%NAME%",
    libraryDependencies ++= Seq(
      "edu.berkeley.cs" %% "chisel3" % chiselVersion,
      "edu.berkeley.cs" %% "chiseltest" % "0.5.4" % "test",
      "edu.berkeley.cs" %% "rocketchip" % "1.2.6",
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-Xcheckinit",
      "-P:chiselplugin:genBundleElements",
    ),
    addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % chiselVersion cross CrossVersion.full),
  )

