#include <iostream>
#include "Person.h"
#include "Vehicle.h"
#include "VehicleFactory.h"

using namespace std;
int main() {
    //Person units
    Soldier* maj = new Soldier("Major", "Deployed");
    Medic* med = new Medic("Field Doctor", "in training");
    Mechanic* mech = new Mechanic("Airplane Mechanic", "Deployed");
    Person* civ = new Soldier();

    //Vehicle Units
    Vehicle* plane = new Plane();
    Plane* bomber = new Plane("Bomber", "Damaged");

    //Memento

    cout<< maj->getType() << " attacks with damage " << maj->attack() <<endl;
    cout<< med->getType() << " status: " << med->getState() <<endl;
    cout<< mech->getType() << " status : " << mech->getState() <<endl;
    cout<< civ->getType() << " status : " << civ->getState() <<endl;
    cout<< bomber->getType() << " status: " << bomber->getState() <<endl;
    mech->repair(bomber);

    mech->clone()->interact();
    //Memento Test
    cout<< "Soldier Health: " << maj->getHealth() <<endl;
    med->setMemento(maj->makeBackup());
    maj->setHealth(-25); //attack sim
    cout<< "Soldier was attacked, health now: " << maj->getHealth() <<endl;

    maj->restore(med->getMemento());
    cout<< "Soldier Health: " << maj->getHealth() <<endl;


    return 0;
}
