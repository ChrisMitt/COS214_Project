#ifndef PHASE4_H
#define PHASE4_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

class Phase4 : public PhasesofWar
{
private:
    /* data */
public:
    Phase4();
    ~Phase4();
    virtual void changePhase(WarPhaseChanger* WPC) ;
    virtual string getPhase();
};

#endif