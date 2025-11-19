import SwiftUI

struct ModalView: View {
    var body: some View {
        Text("This is a modal view.")
            .onAppear {
                LifecycleLogger.log("ModalView", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("ModalView", event: "onDisappear")
            }
    }
}

struct ModalView_Previews: PreviewProvider {
    static var previews: some View {
        ModalView()
    }
}
