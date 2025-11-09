package code.lib

import net.liftweb._
import net.liftweb.http._
import net.liftweb.http.rest._
import net.liftweb.json.JsonAST._
import net.liftweb.json.JsonDSL._

object PingRest extends RestHelper {

  serve {
    case JsonGet("api" :: "ping" :: "pong" :: Nil, req) => sayHello
  }

  val sayHello: JValue = {
    (
      ("ping" -> "pong")
	)
  }
}
