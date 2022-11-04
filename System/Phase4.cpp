#include "Phase4.h"
#include "Phase5.h"

using namespace std;

Phase4::Phase4() : PhasesofWar()
{
}

Phase4::~Phase4()
{
}

void Phase4::changePhase(WarPhaseChanger* WPC) 
{
    WPC->setPhase(new Phase5());
}


string Phase4::getPhase()
{
    return "Post-Conflict";
}