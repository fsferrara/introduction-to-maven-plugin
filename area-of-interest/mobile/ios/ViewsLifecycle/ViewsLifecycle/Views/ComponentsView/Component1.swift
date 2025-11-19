import SwiftUI

struct Component1: View {
    var body: some View {
        Text("Hello, world!")
            .onAppear {
                LifecycleLogger.log("Component1", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("Component1", event: "onDisappear")
            }
    }
}
