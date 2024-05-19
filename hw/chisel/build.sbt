// See README.md for license details.

//ThisBuild / scalaVersion     := "2.13.12"
//ThisBuild / version          := "0.1.0"
//ThisBuild / organization     := "%ORGANIZATION%"

//val chiselVersion = "6.2.0"

//lazy val root = (project in file("."))
  //.settings(
    //name := "ChaosCore",
    //libraryDependencies ++= Seq(
      //"org.chipsalliance" %% "chisel" % chiselVersion,
      //"org.scalatest" %% "scalatest" % "3.2.16" % "test",
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

ThisBuild / scalaVersion     := "2.13.12"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "%ORGANIZATION%"

val chiselVersion = "5.1.0"

lazy val root = (project in file("."))
  .settings(
    name := "%ChaosCore%",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
      "org.scalatest" %% "scalatest" % "3.2.16" % "test",
      "edu.berkeley.cs" %% "chiseltest" % "5.0.2" % "test"
    ),
    scalacOptions ++= Seq(
      "-language:reflectiveCalls",
      "-deprecation",
      "-feature",
      "-Xcheckinit",
      "-Ymacro-annotations",
    ),
    addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chiselVersion cross CrossVersion.full),
  )
