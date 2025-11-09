import Foundation

struct NonMutatingStruct {
    var field: String
    var attributes: [String:String]
    
//    func addAttribute(key: String, value: String) {
//        self.attributes["key"] = "value"
//    }
}

struct MutatingStruct {
    var field: String
    var attributes: [String:String]
    
    mutating func addAttribute(key: String, value: String) {
        attributes[key] = value
    }
}

private func address(o: UnsafeRawPointer) -> Int {
    return Int(bitPattern: o)
}

private func printStructWithAddress(_ inputStruct: inout MutatingStruct) {
    print((NSString(format: "%p", address(o: &inputStruct)) as String) + " > " + "\(inputStruct)")
}

private func mutateMyStruct(_ inputStruct: MutatingStruct) {
    // Cannot use mutating member on immutable value: 'inputStruct' is a 'let' constant
    //inputStruct.addAttribute(key: "key3", value: "value3")
    return
}

func mutatingStruct() {
    var myMutatingStruct = MutatingStruct(field: "start", attributes: [:])
    var myMutatingStruct2 = MutatingStruct(field: "start", attributes: [:])
    
    printStructWithAddress(&myMutatingStruct)
    printStructWithAddress(&myMutatingStruct2)
    
    
    myMutatingStruct.addAttribute(key: "key", value: "value")
    printStructWithAddress(&myMutatingStruct)
    myMutatingStruct = myMutatingStruct2
    
    myMutatingStruct.addAttribute(key: "key2", value: "value2")
    printStructWithAddress(&myMutatingStruct)
    
    myMutatingStruct.addAttribute(key: "key", value: "override value")
    printStructWithAddress(&myMutatingStruct)
}
