import SwiftUI

struct NavView: View {
    var body: some View {
        Text("This is a navigation view.")
            .onAppear {
                LifecycleLogger.log("NavView", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("NavView", event: "onDisappear")
            }
    }
}

struct NavView_Previews: PreviewProvider {
    static var previews: some View {
        NavView()
    }
}
