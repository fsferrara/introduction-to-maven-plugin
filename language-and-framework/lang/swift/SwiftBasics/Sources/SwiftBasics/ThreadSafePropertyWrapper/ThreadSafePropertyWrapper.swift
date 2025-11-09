import Foundation

internal class ThreadSafePropertyWrapper {

    static func main() {
        let counter = Counter()

        let semaphore = DispatchSemaphore(value: 0)

        DispatchQueue.concurrentPerform(iterations: 10000) { _ in
            _ = counter.read()
        }

        DispatchQueue.concurrentPerform(iterations: 10) { _ in
            _ = semaphore.wait(timeout: DispatchTime.now() + .seconds(1))
            counter.update()
            semaphore.signal()
        }
    }

    class Counter {
        @EnsureThreadSafety private var dic = ["hello": "world"]
        func update() {
            dic["hello"] = "world2"
        }
        func read() -> String? {
            dic["hello"]
        }
    }

    @propertyWrapper internal class EnsureThreadSafety<T> {
        private let queue: Dispatch.DispatchQueue
        private var value: T

        public init(wrappedValue: T) {
            queue = Dispatch.DispatchQueue(label: "ETS-\(UUID().uuidString)", attributes: .concurrent)
            value = wrappedValue
        }

        public var wrappedValue: T {
            get {
                return queue.sync { value }
            }
            set {
                queue.async(flags: .barrier) {
                    self.value = newValue
                }
            }
        }
    }


}
