#include <iostream>
#include "UnitFactory.h"
#include "PersonFactory.h"
#include "VehicleFactory.h"
#include "Person.h"
#include "Vehicle.h"

int main()
{
   //Begin
   cout<< "///////////////////Testing The///////////////////" <<endl;
   cout<< "////////////////////Factories////////////////////" <<endl;

    // factories
    int numFacs = 2;
    UnitFactory* factories[numFacs];
    factories[0] = new VehicleFactory();
    factories[1] = new PersonFactory();

    //Vehicles
    int numV;
    cout<< "How many vehicles are there?" <<endl;
    cin>>numV;
    Vehicle** vehicles = new Vehicle*[numV];
    int vehicleType;
    string subType;
    for (int i = 0; i < numV; i++)
    {
        cout<< "What is the vehicle type of vehicle " << i+1 << "? "<<endl;
        cout<< "0 == Tank" <<endl;
        cout<< "1 == Plane" <<endl;
        cout<< "2 == Ship" <<endl;
        cin>>vehicleType;
        if (vehicleType == 0)
        {
            vehicles[i] = factories[0]->createVehicle("tank", "Rooikat");
        }
        else if (vehicleType == 1)
        {
            vehicles[i] = factories[0]->createVehicle("ship", "SAS Johanna van der Merwe");
        }
        else if (vehicleType == 2)
        {
            vehicles[i] = factories[0]->createVehicle("plane", "Atlas Cheetah");
        }
    }

    //Persons
    int numP;
    cout<< "How many persons are there?" <<endl;
    cin>>numP;
    Person** persons = new Vehicle*[numP];
    int personType;
    string subType;
    for (int i = 0; i < numP; i++)
    {
        cout<< "What is the person type of person " << i+1 << "? "<<endl;
        cout<< "0 == Soldier" <<endl;
        cout<< "1 == Medic" <<endl;
        cout<< "2 == Mechanic" <<endl;
        cin>>personType;
        if (personType == 0)
        {
            persons[i] = factories[0]->createVehicle("soldier", "Major");
        }
        else if (personType == 1)
        {
            persons[i] = factories[0]->createVehicle("medic", "Nurse");
        }
        else if (personType == 2)
        {
            persons[i] = factories[0]->createVehicle("mechanic", "Apprentice");
        }
    }
    return 0;
}