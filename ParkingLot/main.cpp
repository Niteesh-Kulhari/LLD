#include "Vehicle.hpp"
#include "ParkingSpot.hpp"
#include "ParkingLot.hpp"
#include <iostream>

using namespace std;

void printResult(string testName, bool condition)
{
    cout << testName << " -> " << (condition ? "PASSED ✅" : "FAILED ❌") << endl;
}

int main()
{
    cout << "========== PARKING LOT TESTS ==========\n\n";

    Vehicle car("ABC123", VehicleType::CAR, "RED");
    Vehicle motorcycle("ABC456", VehicleType::MOTORCYCLE, "BLACK");
    Vehicle truck("XYZ999", VehicleType::TRUCK, "GREEN");
    Vehicle anotherCar("DEF111", VehicleType::CAR, "BLUE");

    ParkingLot lot(1, 1, 1); // 1 compact, 1 regular, 1 large

    // =============================
    // 1. Basic Parking Test
    // =============================
    bool parked = lot.ParkVehicle(&motorcycle);
    printResult("Test 1: Park motorcycle", parked);

    // =============================
    // 2. Duplicate Parking
    // =============================
    bool duplicate = lot.ParkVehicle(&motorcycle);
    printResult("Test 2: Duplicate parking fails", !duplicate);

    // =============================
    // 3. Park more vehicles
    // =============================
    bool carParked = lot.ParkVehicle(&car);
    bool truckParked = lot.ParkVehicle(&truck);

    printResult("Test 3: Car parked", carParked);
    printResult("Test 4: Truck parked", truckParked);

    // =============================
    // 4. Parking when full
    // =============================
    bool shouldFail = lot.ParkVehicle(&anotherCar);
    printResult("Test 5: Parking when full fails", !shouldFail);

    // =============================
    // 5. Find Vehicle
    // =============================
    ParkingSpot *found = lot.findVehicle("ABC123");
    printResult("Test 6: Find existing vehicle", found != nullptr);

    ParkingSpot *notFound = lot.findVehicle("INVALID");
    printResult("Test 7: Find non-existing vehicle", notFound == nullptr);

    // =============================
    // 6. Remove Vehicle
    // =============================
    Vehicle *removed = lot.removeVehicle("ABC123");
    printResult("Test 8: Remove existing vehicle", removed != nullptr);

    Vehicle *removedAgain = lot.removeVehicle("ABC123");
    printResult("Test 9: Remove same vehicle again fails", removedAgain == nullptr);

    // =============================
    // 7. Park after freeing space
    // =============================
    bool parkAgain = lot.ParkVehicle(&anotherCar);
    printResult("Test 10: Park after freeing spot", parkAgain);

    // =============================
    // 8. Null Vehicle Test
    // =============================
    bool nullTest = lot.ParkVehicle(nullptr);
    printResult("Test 11: Null vehicle parking fails", !nullTest);

    // =============================
    // 9. Empty License Plate
    // =============================
    ParkingSpot *emptySearch = lot.findVehicle("");
    printResult("Test 12: Empty license search fails", emptySearch == nullptr);

    // =============================
    // 10. Spot Fit Tests (direct)
    // =============================
    ParkingSpot compact(100, SpotType::COMPACT);

    bool truckFit = compact.canFitVehicle(&truck);
    bool bikeFit = compact.canFitVehicle(&motorcycle);
    bool carFit = compact.canFitVehicle(&car);

    printResult("Test 13: Truck cannot fit in compact", !truckFit);
    printResult("Test 14: Motorcycle fits in compact", bikeFit);
    printResult("Test 15: Car cannot fit in compact (your logic)", !carFit);

    // =============================
    // 11. Spot remove test
    // =============================
    ParkingSpot testSpot(200, SpotType::LARGE);
    testSpot.parkVehicle(&truck);

    Vehicle *removedFromSpot = testSpot.removeVehicle();
    printResult("Test 16: Remove from spot works", removedFromSpot != nullptr);

    printResult("Test 17: Spot becomes available", testSpot.isAvailable());

    // =============================
    // 12. Final State Validation
    // =============================
    int capacity = lot.getCapacity();
    int available = lot.getAvailableSpots();

    bool validState = (available >= 0 && available <= capacity);
    printResult("Test 18: Valid capacity state", validState);

    cout << "\n========== FINAL LOT STATUS ==========\n";
    lot.displayInfo();
    lot.displayOccupancy();

    return 0;
}