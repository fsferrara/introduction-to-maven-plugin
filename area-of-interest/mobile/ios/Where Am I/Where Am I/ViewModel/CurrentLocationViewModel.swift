import Foundation
import CoreLocation

class CurrentLocationViewModel: ObservableObject {
    private let locationModel: LocationModel
    private let placemarkFetcher: PlacemarkFetcher
    @Published var location: CLLocation?
    @Published var placemark: CLPlacemark?

    init() {
        self.locationModel = LocationModelImpl()
        self.placemarkFetcher = PlacemarkFetcherImpl()
    }

    func fetchCurrentLocation() {
        locationModel.fetchCurrentLocation() { [weak self] location in
            if let location {
                self?.location = location
                self?.placemarkFetcher.fetchFirstPlacemark(from: location) { [weak self] placemark in
                    self?.placemark = placemark
                }
            }
        }
    }

    func fetchLastKnownLocation() {
        if let location = locationModel.getLastKnownLocation() {
            self.location = location
            self.placemarkFetcher.fetchFirstPlacemark(from: location) { [weak self] placemark in
                self?.placemark = placemark
            }
        }
    }
}
