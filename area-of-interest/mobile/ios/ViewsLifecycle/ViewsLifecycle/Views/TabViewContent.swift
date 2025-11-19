import SwiftUI

struct TabViewContent: View {
    let tabName: String
    var body: some View {
        Text("This is the content for \(tabName).")
            .onAppear {
                LifecycleLogger.log("TabViewContent (\(tabName))", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("TabViewContent (\(tabName))", event: "onDisappear")
            }
    }
}

struct TabViewContent_Previews: PreviewProvider {
    static var previews: some View {
        TabViewContent(tabName: "Tab 1")
    }
}
