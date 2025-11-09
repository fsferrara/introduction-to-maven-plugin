func tuple() {
    typealias MyTuple = (name: String, age: Int)

    let tupla: MyTuple = ("Carlo", 49)

    print(tupla)

    let (a, _) = tupla
    print("Destructured: \(a)")
}
