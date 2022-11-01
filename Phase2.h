#ifndef PHASE2_H
#define PHASE2_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

class Phase2 : public PhasesofWar
{
private:
    /* data */
public:
    Phase2();
    ~Phase2();
    virtual void changePhase(WarPhaseChanger* WPC) ;
    virtual string getPhase();
};

#endif