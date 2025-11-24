import SwiftUI

struct ViewWrapper: View {
    private let innerView: () -> any View

    public init(innerView: @escaping () -> any View) {
        self.innerView = innerView
        MyLogger.log("ViewWrapper", event: "init")
    }

    var body: some View {
        AnyView(
            innerView()
                .onAppear {
                    MyLogger.log("innerView", event: "onAppear")
                }
                .onDisappear {
                    MyLogger.log("innerView", event: "onDisappear")
                }
        )
        .onAppear {
            MyLogger.log("ViewWrapper", event: "onAppear")
        }
        .onDisappear {
            MyLogger.log("ViewWrapper", event: "onDisappear")
        }
    }
}
