#ifndef WARPHASECHANGER_H
#define WARPHASECHANGER_H

#include "PhasesofWar.h"
#include "WarStrategy.h"

#include <iostream>

using namespace std;

class PhasesofWar;

class WarPhaseChanger
{
    private:
        /* data */
        PhasesofWar* War_phase;
        WarStrategy* CountryStrat;
    public:

        WarPhaseChanger();
        ~WarPhaseChanger();
        void setStrategy(WarStrategy* Strategy);
        void Engage();  
        void setPhase(PhasesofWar* phase);
        void requestPhase();
        string getPhase();

};

#endif