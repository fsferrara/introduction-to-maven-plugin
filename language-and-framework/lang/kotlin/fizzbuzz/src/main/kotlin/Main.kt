fun main(args: Array<String>) {
    println("[Starting] - program arguments: ${args.joinToString()}")

    val fizzbuzz = FizzBuzz(78, 345)
    fizzbuzz.checkDivisibility()
    println("[Stop]")
}

class FizzBuzz(val a: Int, val b: Int) {

    fun play() {
        (1..100).forEach { i: Int -> when {
            i % (a*b) == 0 -> println("$i : FizzBuzz");
            i % (a) == 0 -> println("$i : Fizz");
            i % (b) == 0 -> println("$i : Buzz");
            else -> println("$i : $i");
        } }
    }

    fun checkDivisibility() {
        (1..999999999).forEach { i: Int ->
            if ((i%a == 0) && (i%b == 0) && (i%(a*b) != 0)) {
                println("$i is divisible for both but not for the sum")
            }
        }
    }
}
