#ifndef PHASE1_H
#define PHASE1_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

class Phase1 : public PhasesofWar
{
private:
    /* data */
public:
    Phase1();
    ~Phase1();
    virtual void changePhase(WarPhaseChanger* WPC) ;
    virtual string getPhase();
};

#endif
