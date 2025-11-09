struct MyKeyPathStruct {
    var name: String
    var age: Int
}

func keyPath() {
    let inputEnum = MyEnum.sayHello(name: "Swift")

    print("starting...")

    var joe = MyKeyPathStruct(name: "Joe", age: 25)
    let keyPath = \MyKeyPathStruct.age
    joe[keyPath: keyPath] = 26
    print(joe)


    print("end!")
}
