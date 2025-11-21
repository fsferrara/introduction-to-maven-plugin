import SwiftUI

struct OnViewModifier: ViewModifier {
    var block: (() -> Void)?

    public init(block action: (() -> Void)? = nil) {
        self.block = action
    }

    public func body(content: Content) -> some View {
        content
            .onAppear {
                block?()
            }
    }
}

public extension View {
    func onViewModifier(block action: (() -> Void)? = nil) -> some View {
        modifier(OnViewModifier(block: action))
    }
}


struct Component2: View {
    var body: some View {
        HStack {
            if true {
                //EmptyView()
                Color.clear
                    .onViewModifier {
                        LifecycleLogger.log("Component2 - EmptyView", event: "onViewModifier")
                    }
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
