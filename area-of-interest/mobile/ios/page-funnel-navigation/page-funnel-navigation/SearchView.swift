import SwiftUI

struct SearchView: View {
    var body: some View {
        NavigationView {
            VStack {
                Text("SearchView")
                NavigationLink(destination: ResultsView()) {
                    Text("Navigate to: ResultsView")
                }
            }
            .padding()
        }
    }
}

#Preview {
    HomeView()
}
