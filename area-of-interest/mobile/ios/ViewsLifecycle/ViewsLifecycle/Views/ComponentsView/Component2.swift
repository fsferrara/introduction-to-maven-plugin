import SwiftUI

struct Component2: View {
    var body: some View {
        HStack {
            if false {
                EmptyView()
            }
        }
            .onAppear {
                LifecycleLogger.log("Component2", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("Component2", event: "onDisappear")
            }
    }
}
