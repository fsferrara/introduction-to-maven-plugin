class C() {
	var acc:Int = 0

	def minc(x:Int) {acc += x}

	val finc = { (x:Int) => acc +=x }
}
