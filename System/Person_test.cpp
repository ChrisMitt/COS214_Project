#include <iostream>
#include "Person.h"
#include "Vehicle.h"
#include "VehicleFactory.h"
#include "Decorator.h"

using namespace std;
int main() {
    //Person units
    Soldier* maj = new Soldier("Major", "Deployed", new ExtraDamage(new Research));
    Medic* med = new Medic("Field Doctor", "in training");
    Mechanic* mech = new Mechanic("Airplane Mechanic", "Deployed");
    Person* civ = new Soldier();



    //Vehicle Units
    Vehicle* plane = new Plane();
    Plane* bomber = new Plane("Bomber", "Damaged", new ExtraDamage(new Research));

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

    cout<< "Bomber Armour: " << bomber->getAmour() <<endl;
    mech->setMemento(bomber->makeBackup());
    bomber->setArmour(-75);
    cout<< "Bomber was shot, armour now at " << bomber->getAmour() <<endl;
    bomber->restore(mech->getMemento());
    cout<< "Bomber was repaired by " << mech->getType() << ". Bomber armour now at " << bomber->getAmour() <<endl;

    //Decorator
    cout<< "Bomber decorator:" <<endl;
    cout<< bomber->research() <<endl;
    if(maj->research() > 50 || maj->research() < 0){
        cout<< "True" << endl;
    }
    else{
        cout<< "False" <<endl;
        int dam = maj->research();
        cout << dam <<endl;
    }


    return 0;
}
