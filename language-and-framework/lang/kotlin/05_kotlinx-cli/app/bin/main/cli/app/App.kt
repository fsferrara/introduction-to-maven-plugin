package cli.app

import kotlinx.cli.*


object App {
    const val appName = "CLI App"
    const val version = "0.0.1"
}

fun main(args: Array<String>) {
    val parser = ArgParser("${App.appName}:: ${App.version}")
    val debug by parser.option(ArgType.Boolean, shortName = "d", description = "Turn on debug mode").default(false)
    parser.parse(args)

	println("This is a simple CLI App")

	if (debug) println(App.version)
}

