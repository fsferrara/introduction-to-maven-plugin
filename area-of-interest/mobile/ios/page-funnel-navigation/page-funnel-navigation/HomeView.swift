import SwiftUI

struct HomeView: View {

    @State private var navigateToSearchView = false

    var body: some View {
        NavigationView {
            VStack {
                Text("HomeView")
                    .foregroundColor(.blue)
                List {
                    Button("Navigate to: SearchView") {
                        navigateToSearchView = true
                    }
                }
            }
            .padding()
            .background(
                NavigationLink(destination: SearchView(), isActive: $navigateToSearchView) {
                    EmptyView()
                }
                .hidden()
            )
        }
    }
}

#Preview {
    HomeView()
}
