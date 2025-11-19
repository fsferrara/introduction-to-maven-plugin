import SwiftUI

struct ComponentsView: View {
    var body: some View {
        VStack {
            Text("This is a view with multpliple views in it.")
            Component1()
            Component2()
        }
            .onAppear {
                LifecycleLogger.log("ComponentsView", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("ComponentsView", event: "onDisappear")
            }
    }
}

struct ComponentsView_Previews: PreviewProvider {
    static var previews: some View {
        ComponentsView()
    }
}
