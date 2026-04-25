#include <iostream>
#include "repository.h"
#include "lotService.h"
#include "bookingManager.h"
#include "user.h"
#include "vehicle.h"
#include "parkingSpot.h"

using namespace std;

int main()
{
    Repository repo;
    LotService lot(repo);
    bookingManager manager(repo, lot);

    User u1("U1", "Niteesh", "nkulhari96@gmail.com", "123456");
    repo.addUser(u1);

    Vehicle v1("V1", "AKAJBAJ", VehicleType::Car);
    repo.addVehicle(v1);

    for (int i = 0; i < 10; i++)
    {
        string spotName = "s" + to_string(i);
        ParkingSpot spot(spotName, spotType::Small, spotStatus::Available);
        repo.addParkingSpot(spot);
    }

    for (int i = 10; i < 20; i++)
    {
        string spotName = "s" + to_string(i);
        ParkingSpot spot(spotName, spotType::Small, spotStatus::Available);
        repo.addParkingSpot(spot);
    }

    for (int i = 20; i < 30; i++)
    {
        string spotName = "s" + to_string(i);
        ParkingSpot spot(spotName, spotType::Small, spotStatus::Available);
        repo.addParkingSpot(spot);
    }

    try
    {
        cout << manager.createBooking(u1, v1) << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}