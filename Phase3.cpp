#include "Phase3.h"
#include "Phase4.h"

using namespace std;

Phase3::Phase3() : PhasesofWar()
{
}

Phase3::~Phase3()
{
}

void Phase3::changePhase(WarPhaseChanger* WPC) 
{
    WPC->setPhase(new Phase4());
}


string Phase3::getPhase()
{
    return "Fighting";
}