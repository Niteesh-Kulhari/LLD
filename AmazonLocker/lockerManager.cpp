#include "lockerManager.h"
#include "repository.h"
using namespace std;

LockerManager::LockerManager(UserRepo &ur, PackageRepo &pr, LockerRepo &lr) : userRepo(ur), packageRepo(pr), lockerRepo(lr) {}

string LockerManager::assignPackage(const string &packageId, const string &userId, const string &pinCode)
{
    Package *pkg = packageRepo.getPackage(packageId);
    User *user = userRepo.getUser(userId);

    if (!pkg || !user)
    {
        return "Invalid User or Package";
    }

    for (auto &[id, locker] : lockerRepo.getAllLockers())
    {
        if (locker.isAvailable() && static_cast<int>(locker.getType()) >= static_cast<int>(pkg->getSize()))
        {

            locker.assignPackage(packageId, pinCode);
            return "Package assigned to locker " + locker.getId();
        }
    }

    return "No suitable locker available";
}

bool LockerManager::pickupPackage(const string &lockerId, const string &pinCode)
{
    Locker *temp = lockerRepo.getLocker(lockerId);
    if (!temp)
        return false;

    if (temp->verifyPin(pinCode))
    {
        temp->release();
        return true;
    }
    return false;
}