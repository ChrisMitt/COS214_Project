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

    int numV;
    cout<< "How many vehicles are there?" <<endl;
    cin>>numV;
    Vehicle** vehicles = new Vehicle*[numV];
    int vehicleType;
    string defmov;
    for (int i = 0; i < numV; i++)
    {
        cout<< "What is the vehicle type of vehicle " << i+1 << "? "<<endl;
        cout<< "0 == Tank" <<endl;
        cout<< "1 == Plane" <<endl;
        cout<< "2 == Ship" <<endl;
        cin>>vehicleType;
        if (vehicleType == 0)
        {
            vehicles[i] = factories[0]->createVehicle("tank", );
        }
        else if (vehicleType == 1)
        {
            vehicles[i] = factories[0]->createVehicle("ship", );
        }
        else if (vehicleType == 2)
        {
            vehicles[i] = factories[0]->createVehicle("plane", );
        }
        //cout<<factories[i]<<endl;
    }

    
    return 0;
}