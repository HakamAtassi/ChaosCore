
// See README.md for license details.
ThisBuild / scalaVersion     := "2.13.14"
ThisBuild / version          := "0.1.0"
ThisBuild / organization     := "%ORGANIZATION%"

//val chiselVersion = "6.4.2"
val chiselVersion    = "6.4.2-tywaves-SNAPSHOT" // Local version of chisel

lazy val root = (project in file("."))
  .settings(
    name := "ChaosCore",
    libraryDependencies ++= Seq(
      "org.chipsalliance" %% "chisel" % chiselVersion,
      "org.scalatest" %% "scalatest" % "3.2.16" % "test",
      "org.scalameta" %% "scalameta" % "4.9.8"
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


