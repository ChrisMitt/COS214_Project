#ifndef PHASE5_H
#define PHASE5_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

class Phase5 : public PhasesofWar
{
private:
    /* data */
public:
    Phase5();
    ~Phase5();
    virtual void changePhase(WarPhaseChanger* WPC) ;
    virtual string getPhase();
};

#endif