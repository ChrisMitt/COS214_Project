#include <iostream>
#include "Person.h"
#include "Vehicle.h"
#include "VehicleFactory.h"

using namespace std;
int main() {

    Soldier* maj = new Soldier("Major", "Deployed");
    Medic* med = new Medic("Field Doctor", "in training");
    Mechanic* mech = new Mechanic("Airplane Mechanic", "Deployed");
    Person* civ = new Soldier();
    Vehicle* plane = new Plane();
    Plane* bomber = new Plane("Bomber", "Damaged");
    //VehicleFactory* Vfac = new VehicleFactory();



    cout<< maj->getType() << " attacks with damage " << maj->attack() <<endl;
    cout<< med->getType() << " status: " << med->getStatus() <<endl;
    cout<< mech->getType() << " status : " << mech->getStatus() <<endl;
    cout<< civ->getType() << " status : " << civ->getStatus() <<endl;
    cout<< bomber->getType() << " status: " << bomber->getStatus() <<endl;
    mech->repair(bomber);

    mech->clone()->interact();

    return 0;
}
