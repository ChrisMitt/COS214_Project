#ifndef PHASESOFWAR_H
#define PHASESOFWAR_H

#include "WarPhaseChanger.h"
#include <iostream>

//sing namespace std;

class WarPhaseChanger;

class PhasesofWar
{
private:
    /* data */
public:
    PhasesofWar();
    virtual ~PhasesofWar();
    virtual void changePhase(WarPhaseChanger* WPC) = 0;
    virtual std::string getPhase() = 0;
};

#endif