import CoreLocation

public protocol PlacemarkFetcher {
    func fetchFirstPlacemark(from location: CLLocation, completion: @escaping ((CLPlacemark?) -> Void))
}

struct PlacemarkFetcherImpl: PlacemarkFetcher {
    private let geocoder: CLGeocoder

    init() {
        self.geocoder = CLGeocoder()
    }

    func fetchFirstPlacemark(from location: CLLocation, completion: @escaping ((CLPlacemark?) -> Void)) {
        geocoder.reverseGeocodeLocation(location) { (placemarks, error) in
            if let error = error {
                print("Reverse geocoding failed: \(error.localizedDescription)")
                return
            }
            let placemark: CLPlacemark? = placemarks?.first ?? nil
            completion(placemark)
        }
    }
}
