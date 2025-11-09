import SwiftUI

struct MissingLocationView: View {
    @StateObject private var viewModel: MissingLocationViewModel

    init(viewModel: MissingLocationViewModel? = nil) {
        _viewModel = StateObject(wrappedValue: viewModel ?? MissingLocationViewModel())
    }

    var body: some View {
        VStack {
            if viewModel.authorizationStatus == .notDetermined {
                Button("Request Location Permission") {
                    viewModel.requestPermission()
                }
                .padding()
                .buttonStyle(.borderedProminent)
                .controlSize(.large)
            } else if viewModel.authorizationStatus == .denied || viewModel.authorizationStatus == .restricted {
                Text("Location access was denied or restricted. Please enable it in Settings.")
            } else {
                Text("Fetching location...")
            }
        }
    }
}

#Preview {
    return MissingLocationView()
}
