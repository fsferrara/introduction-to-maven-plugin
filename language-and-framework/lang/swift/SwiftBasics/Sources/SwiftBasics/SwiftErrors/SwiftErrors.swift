import Foundation

enum MyEnumError: Error {
    case noMessage
    case withMessage(String)
    case withCode(Int)
}

struct MyStructError: Error {
    let message: String
}

class MyClassError: Error {
    let code: Int
    let description: String

    init(code: Int, description: String) {
        self.code = code
        self.description = description
    }
}

func swiftErrors() {

    let foundationError = NSError(domain: "my foundation error", code: 1234, userInfo: [NSLocalizedDescriptionKey: "This is a foundation error description."])
    print("Existing Foundation error: \(foundationError)")

    let myEnumError = MyEnumError.withMessage("This is my custom error message in the enum error.")
    print("Enum based error: \(myEnumError)")


    let myStructError = MyStructError(message: "This is my custom error message in the struct.")
    print("Struct based error: \(myStructError)")

    let myClassError = MyClassError(code: 1234, description: "This is my custom error message in the class.")
    print("Class based error: \(myClassError)")

    print("end!")
}
