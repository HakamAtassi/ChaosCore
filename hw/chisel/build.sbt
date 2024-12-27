//val chisel6Version = "6.5.0"
//val chiselTestVersion = "6.0.0"
//val scalaVersionFromChisel = "2.13.12"

//val chisel3Version = "3.6.1"


//lazy val commonSettings = Seq(
  //organization := "edu.berkeley.cs",
  //version := "1.6",
  //scalaVersion := scalaVersionFromChisel,
  //scalacOptions ++= Seq(
    //"-deprecation",
    //"-unchecked",
    //"-Ytasty-reader",
    //"-Ymacro-annotations"), // fix hierarchy API
  //allDependencies := {
    //// drop specific maven dependencies in subprojects in favor of Chipyard's version
    //val dropDeps = Seq(("edu.berkeley.cs", "rocketchip"))
    //allDependencies.value.filterNot { dep =>
      //dropDeps.contains((dep.organization, dep.name))
    //}
  //},
  //libraryDependencies += "com.lihaoyi" %% "sourcecode" % "0.3.1",
  //libraryDependencies += "org.scala-lang" % "scala-reflect" % scalaVersion.value,
  //libraryDependencies += "org.chipsalliance" %% "chisel" % chisel6Version,

  //exportJars := true,
  //resolvers ++= Seq(
    //Resolver.sonatypeRepo("snapshots"),
    //Resolver.sonatypeRepo("releases"),
    //Resolver.mavenLocal))


//val rocketChipDir = file("deps/rocketchip")

///**
  //* It has been a struggle for us to override settings in subprojects.
  //* An example would be adding a dependency to rocketchip on midas's targetutils library,
  //* or replacing dsptools's maven dependency on chisel with the local chisel project.
  //*
  //* This function works around this by specifying the project's root at src/ and overriding
  //* scalaSource and resourceDirectory.
  //*/
//def freshProject(name: String, dir: File): Project = {
  //Project(id = name, base = dir / "src")
    //.settings(
      //Compile / scalaSource := baseDirectory.value / "main" / "scala",
      //Compile / resourceDirectory := baseDirectory.value / "main" / "resources"
    //)
//}

//lazy val chisel6Settings = Seq(
  //libraryDependencies ++= Seq("org.chipsalliance" %% "chisel" % chisel6Version),
  //addCompilerPlugin("org.chipsalliance" % "chisel-plugin" % chisel6Version cross CrossVersion.full)
//)
//lazy val chisel3Settings = Seq(
  //libraryDependencies ++= Seq("edu.berkeley.cs" %% "chisel3" % chisel3Version),
  //addCompilerPlugin("edu.berkeley.cs" % "chisel3-plugin" % chisel3Version cross CrossVersion.full)
//)

//lazy val chiselSettings = chisel6Settings ++ Seq(
  //libraryDependencies ++= Seq(
    //"org.apache.commons" % "commons-lang3" % "3.12.0",
    //"org.apache.commons" % "commons-text" % "1.9"
  //)
//)




//lazy val scalaTestSettings =  Seq(
  //libraryDependencies ++= Seq(
    //"org.scalatest" %% "scalatest" % "3.2.+" % "test"
  //)
//)

////// -- Rocket Chip --


//lazy val hardfloat = freshProject("hardfloat", file("deps/berkeley-hardfloat/hardfloat"))
  //.settings(chiselSettings)
  //.settings(commonSettings)
  //.settings(scalaTestSettings)

//lazy val diplomacy = freshProject("diplomacy", file("deps/diplomacy/diplomacy"))
  //.dependsOn(cde)
  //.settings(commonSettings)
  //.settings(chiselSettings)
  //.settings(Compile / scalaSource := baseDirectory.value / "diplomacy")

//lazy val cde = (project in file("deps/cde"))
  //.settings(commonSettings)
  //.settings(Compile / scalaSource := baseDirectory.value / "cde/src/chipsalliance/rocketchip")

//lazy val rocketMacros  = (project in rocketChipDir / "macros")
  //.settings(commonSettings)
  //.settings(scalaTestSettings)


//lazy val rocketchip_blocks = (project in file("deps/rocket-chip-blocks"))
  //.dependsOn(rocketchip)
  //.settings(libraryDependencies ++= rocketLibDeps.value)
  //.settings(commonSettings)


//lazy val rocketchip = freshProject("rocketchip", rocketChipDir)
  //.dependsOn(hardfloat, rocketMacros, diplomacy, cde)
  //.settings(commonSettings)
  //.settings(chiselSettings)
  //.settings(scalaTestSettings)
  //.settings(
    //libraryDependencies ++= Seq(
      //"com.lihaoyi" %% "mainargs" % "0.5.0",
      //"org.json4s" %% "json4s-jackson" % "4.0.5",
      //"org.scala-graph" %% "graph-core" % "1.13.5"
    //)
  //)


//lazy val rocketLibDeps = (rocketchip / Keys.libraryDependencies)

//lazy val root = (project in file("."))
  //.dependsOn(rocketchip, rocketchip_blocks)
  //.settings(libraryDependencies ++= rocketLibDeps.value)
  //.settings(
    //libraryDependencies ++= Seq(
      //"org.reflections" % "reflections" % "0.10.2"
    //)
  //)
  //.settings(commonSettings)