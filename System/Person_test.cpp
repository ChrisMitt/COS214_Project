#include <iostream>
#include "Person.h"
#include "Vehicle.h"
#include "VehicleFactory.h"
#include "Decorator.h"
#include "ResourceManagement.h"
#include "CountryObserver.h"
#include "Country.h"

using namespace std;
int main() {
    //Person units
    Research* re = new Research;
    Soldier* maj = new Soldier("Major", "Deployed", new ExtraHealth(re));
    Medic* med = new Medic("Field Doctor", "in training");
    Mechanic* mech = new Mechanic("Airplane Mechanic", "Deployed");
    Person* civ = new Soldier();



    //Vehicle Units
    Vehicle* plane = new Plane();
    ExtraDamage* ed = new ExtraDamage(re);
    Plane* bomber = new Plane("Bomber", "Damaged", ed);

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

    cout<< "Bomber Armour: " << bomber->getArmour() <<endl;
    mech->setMemento(bomber->makeBackup());
    bomber->setArmour(-5);
    cout<< "Bomber was shot, armour now at " << bomber->getArmour() <<endl;
    bomber->restore(mech->getMemento());
    cout<< "Bomber was repaired by " << mech->getType() << ". Bomber armour now at " << bomber->getArmour() <<endl;

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

    cout<<endl;
    cout<<"Resources"<<endl;
    Country* co = new Country();
    co->resources = 200;
    cout<<co->resources<<endl;
    ResourceManagement* rs = new UnitProducer(60 ,4);
    rs->add(new UnitProducer(40, 3));
    rs->add(new UnitProducer(20, 2));
    rs->add(new UnitProducer(2, 1));

    int ret = rs->createUpgradedUnit(2, co);
    cout<<co->resources<<endl;

    cout<<endl;
    cout<<"Damage testing"<<endl;
    cout<<maj->research()<<endl;
    cout<<maj->getDamage()<<endl;


    return 0;
}
