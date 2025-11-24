import Foundation

struct MyLogger {
    static func log(_ viewName: String, event: String) {
        print("\(Date()): \(viewName) - \(event)")
    }
}
