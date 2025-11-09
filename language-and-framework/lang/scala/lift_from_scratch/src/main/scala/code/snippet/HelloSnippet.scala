package code.snippet 

import net.liftweb.util.Helpers._
import net.liftweb.util.PassThru

import scala.util.Random
import xml.Text

class HelloSnippet {
  private def fiftyFifty = Random.nextBoolean

  def render =
    if (fiftyFifty) "*" #> Text("Hello Saverio")
    else PassThru
}
