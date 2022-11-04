#include "Phase5.h"

using namespace std;

Phase5::Phase5() : PhasesofWar()
{
}

Phase5::~Phase5()
{
}

void Phase5::changePhase(WarPhaseChanger* WPC) 
{
    cout<<"Diplomacy succeded and War is Over"<<endl;
}


string Phase5::getPhase()
{
    return "Dilpomacy";
}