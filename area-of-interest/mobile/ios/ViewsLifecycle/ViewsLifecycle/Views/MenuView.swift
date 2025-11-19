import SwiftUI

struct MenuView: View {
    @State private var isShowingModal = false
    @State private var isShowingFullScreenCover = false

    var body: some View {
        TabView {
            NavigationView {
                VStack(spacing: 20) {
                    Button("Show Modal") {
                        isShowingModal = true
                    }
                    .sheet(isPresented: $isShowingModal) {
                        ModalView()
                    }

                    NavigationLink("Show Components View", destination: ComponentsView())

                    NavigationLink("Show Navigation View", destination: NavView())

                    Button("Show Full Screen Cover") {
                        isShowingFullScreenCover = true
                    }
                    .fullScreenCover(isPresented: $isShowingFullScreenCover) {
                        FullScreenCoverView()
                    }
                }
                .navigationTitle("Main Menu")
            }
            .onAppear {
                LifecycleLogger.log("MenuView (NavigationView)", event: "onAppear")
            }
            .onDisappear {
                LifecycleLogger.log("MenuView (NavigationView)", event: "onDisappear")
            }
            .tabItem {
                Image(systemName: "house.fill")
                Text("Home")
            }

            TabViewContent(tabName: "Tab 1")
                .tabItem {
                    Image(systemName: "1.circle.fill")
                    Text("Tab 1")
                }

            TabViewContent(tabName: "Tab 2")
                .tabItem {
                    Image(systemName: "2.circle.fill")
                    Text("Tab 2")
                }
        }
        .onAppear {
            LifecycleLogger.log("MenuView (TabView)", event: "onAppear")
        }
        .onDisappear {
            LifecycleLogger.log("MenuView (TabView)", event: "onDisappear")
        }
    }
}

#Preview {
    MenuView()
}
