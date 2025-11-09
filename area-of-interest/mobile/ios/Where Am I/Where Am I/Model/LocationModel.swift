import CoreLocation

public protocol LocationModel {
    var location: CLLocation? { get }
    var locationServicesEnabled: Bool { get }
    var authorizationStatus: CLAuthorizationStatus { get }
    func isEnabledAndAuthorized() -> Bool
    func requestPermission(_ completion: @escaping ((CLAuthorizationStatus) -> Void))
    func fetchCurrentLocation(_ completion: @escaping (CLLocation?) -> Void)
    func getLastKnownLocation() -> CLLocation?
}

class LocationModelImpl: NSObject, CLLocationManagerDelegate, LocationModel {
    private let locationManager = CLLocationManager()
    private let isUpdatingLocationLock = NSLock()
    var fetchCurrentLocationCompletion: ((CLLocation?) -> Void)?
    var requestPermissionCompletion: ((CLAuthorizationStatus) -> Void)?

    override init() {
        super.init()
        self.locationManager.delegate = self
        self.locationManager.desiredAccuracy = kCLLocationAccuracyBest
    }

    var location: CLLocation? {
        return locationManager.location
    }

    var locationServicesEnabled: Bool {
        return CLLocationManager.locationServicesEnabled()
    }

    var authorizationStatus: CLAuthorizationStatus {
        return locationManager.authorizationStatus
    }

    func requestPermission(_ completion: @escaping ((CLAuthorizationStatus) -> Void)) {
        if self.requestPermissionCompletion == nil {
            self.requestPermissionCompletion = completion
            locationManager.requestWhenInUseAuthorization()
        }
    }

    func isEnabledAndAuthorized() -> Bool {
        return locationServicesEnabled && (authorizationStatus == .authorizedAlways || authorizationStatus == .authorizedWhenInUse)
    }

    func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        requestPermissionCompletion?(manager.authorizationStatus)
        requestPermissionCompletion = nil
    }

    func getLastKnownLocation() -> CLLocation? {
        return locationManager.location
    }

    func fetchCurrentLocation(_ completion: @escaping (CLLocation?) -> Void) {
        if isUpdatingLocationLock.try() {
            defer { isUpdatingLocationLock.unlock() }
            if self.fetchCurrentLocationCompletion == nil {
                self.fetchCurrentLocationCompletion = completion
                locationManager.startUpdatingLocation()
            }
        }
    }

    func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if isUpdatingLocationLock.try() {
            defer { isUpdatingLocationLock.unlock() }
            if self.fetchCurrentLocationCompletion != nil {
                self.locationManager.stopUpdatingLocation() // We only need the location once
                guard let location = locations.last else { return }
                fetchCurrentLocationCompletion?(location)
                fetchCurrentLocationCompletion = nil
            }
        }
    }

    func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print("Failed to get user location: \(error.localizedDescription)")
    }
}
