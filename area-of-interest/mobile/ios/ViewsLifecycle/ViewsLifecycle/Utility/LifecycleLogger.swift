import Foundation

struct LifecycleLogger {
    static func log(_ viewName: String, event: String) {
        print("\(Date()): \(viewName) - \(event)")
    }
}
