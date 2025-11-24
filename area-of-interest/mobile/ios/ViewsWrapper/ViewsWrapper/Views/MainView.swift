import SwiftUI

struct MainView: View {
    @State private var isShowingModal = false
    @State private var isShowingFullScreenCover = false

    var body: some View {
        NavigationView {
            VStack() {
                NavigationLink("Show My View", destination: MyView())
            }
            .navigationTitle("Main Menu")
        }
        .onAppear {
            MyLogger.log("MenuView (NavigationView)", event: "onAppear")
        }
        .onDisappear {
            MyLogger
                .log("MenuView (NavigationView)", event: "onDisappear")
        }
    }
}

#Preview {
    MainView()
}
