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
    //int numFacs = 2;
    //VehicleFactory* vf = new VehicleFactory();
    UnitFactory* factories[2];
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
        cout<< "What is the vehicle " << i+1 << "'s name/model? "<<endl;
        cin>>subType;
        if (vehicleType == 0)
        {
            vehicles[i] = factories[0]->createVehicle("tank", subType);
        }
        else if (vehicleType == 1)
        {
            vehicles[i] = factories[0]->createVehicle("ship", subType);
        }
        else if (vehicleType == 2)
        {
            vehicles[i] = factories[0]->createVehicle("plane", subType);
        }
    }

    //Persons
    int numP;
    cout<< "How many persons are there?" <<endl;
    cin>>numP;
    Person** persons = new Person*[numP];
    int personType;
    //string subType;
    for (int i = 0; i < numP; i++)
    {
        cout<< "What is the person type of person " << i+1 << "? "<<endl;
        cout<< "0 == Soldier" <<endl;
        cout<< "1 == Medic" <<endl;
        cout<< "2 == Mechanic" <<endl;
        cin>>personType;
        cout<< "What is the person " << i+1 << "'s rank/name? "<<endl;
        cin>>subType;
        if (personType == 0)
        {
            persons[i] = factories[1]->createPerson("soldier", subType);
        }
        else if (personType == 1)
        {
            persons[i] = factories[1]->createPerson("medic", subType);
        }
        else if (personType == 2)
        {
            persons[i] = factories[1]->createPerson("mechanic", subType);
        }
    }

    //Deletes
    for (int i = 0; i < numV; i++)
    {
        delete vehicles[i];
    }
    delete [] vehicles;

    for (int i = 0; i < numP; i++)
    {
        delete persons[i];
    }
    delete [] persons;

    for (int i = 0; i < 2; i++)
    {
        delete factories[i];
    }
    //delete [] factories;

    return 0;
}