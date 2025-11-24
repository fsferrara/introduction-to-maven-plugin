import SwiftUI

struct WrappedView: View {
    var body: some View {
        VStack {
            Text("This is a wrapped view 🌯")
        }
        .onAppear {
            MyLogger.log("WrappedView", event: "onAppear")
        }
        .onDisappear {
            MyLogger.log("WrappedView", event: "onDisappear")
        }
    }
}
