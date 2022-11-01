#include "Phase1.h"
#include "Phase2.h"

using namespace std;

Phase1::Phase1() : PhasesofWar()
{
}

Phase1::~Phase1()
{
}

void Phase1::changePhase(WarPhaseChanger* WPC) 
{
    WPC->setPhase(new Phase2());
}


string Phase1::getPhase()
{
    return "Dispute";
}