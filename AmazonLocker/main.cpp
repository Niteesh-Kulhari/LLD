#include <iostream>
#include "repository.h"
#include "lockerManager.h"
using namespace std;

int main()
{
    UserRepo userRepo;
    PackageRepo packageRepo;
    LockerRepo lockerRepo;

    User u1("Niteesh", "nkulhari96@gmail.com", userType::Consumer);
    cout << u1.getName() << endl;
}