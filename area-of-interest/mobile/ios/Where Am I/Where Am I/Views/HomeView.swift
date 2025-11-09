import SwiftUI

struct HomeView: View {
    @StateObject private var currentLocationViewModel = CurrentLocationViewModel()
    @StateObject private var missingLocationViewModel = MissingLocationViewModel()

    var body: some View {
        VStack {
            if missingLocationViewModel.authorizationStatus == .authorizedWhenInUse || missingLocationViewModel.authorizationStatus == .authorizedAlways {
                CurrentLocationView(viewModel: currentLocationViewModel)
            } else {
                MissingLocationView(viewModel: missingLocationViewModel)
            }
        }
    }
}

#Preview {
    HomeView()
}
