func forStyles() {
    for i in 1...5 { print(i) }
    print("\n")

    for i in 1..<5 { print(i) }
    print("\n")

    for i in 1..<5 where i.isMultiple(of: 2) { print(i) }
}
