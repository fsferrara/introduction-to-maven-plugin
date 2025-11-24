import SwiftUI

struct MyView: View {
    var body: some View {
        ViewWrapper {
            WrappedView()
        }
        .onAppear {
            MyLogger.log("MyView", event: "onAppear")
        }
        .onDisappear {
            MyLogger.log("MyView", event: "onDisappear")
        }
    }
}

struct MyView_Previews: PreviewProvider {
    static var previews: some View {
        MyView()
    }
}
