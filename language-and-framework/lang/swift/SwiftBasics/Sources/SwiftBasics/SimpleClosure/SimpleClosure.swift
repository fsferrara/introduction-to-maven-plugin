func applyC(_ value: Int, _ comp: (Int) -> Int) -> Int {
    comp(value)
}

func simpleClosure() {
    _ = applyC(2, { val in
        val * 2
    })

    _ = applyC(2) { val in
        val * 2
    }
}
