#include "Phase2.h"
#include "Phase3.h"

using namespace std;

Phase2::Phase2() : PhasesofWar()
{
}

Phase2::~Phase2()
{
}

void Phase2::changePhase(WarPhaseChanger* WPC) 
{
    WPC->setPhase(new Phase3());
}


string Phase2::getPhase()
{
    return "Conflict";    
}