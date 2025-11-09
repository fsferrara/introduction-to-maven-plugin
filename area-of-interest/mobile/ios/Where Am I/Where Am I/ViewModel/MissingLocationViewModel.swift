import Foundation
import CoreLocation

class MissingLocationViewModel: ObservableObject {
    private let locationModel: LocationModel
    @Published var authorizationStatus: CLAuthorizationStatus

    init() {
        self.locationModel = LocationModelImpl()
        self.authorizationStatus = locationModel.authorizationStatus
    }

    func requestPermission() {
        locationModel.requestPermission() { [weak self] status in
            self?.authorizationStatus = status
        }
    }
}
