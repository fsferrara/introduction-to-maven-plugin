public enum MyEnum {
    case sayHello(name: String)
}

func enumFunctions() {
    let inputEnum = MyEnum.sayHello(name: "Swift")

    print("starting...")

    switch inputEnum {
    case .sayHello(let name):
        print("Hello, \(name)!")
    }

    print("end!")
}
