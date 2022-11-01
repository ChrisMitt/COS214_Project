#ifndef PHASE3_H
#define PHASE3_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

class Phase3 : public PhasesofWar
{
private:
    /* data */
public:
    Phase3();
    ~Phase3();
    virtual void changePhase(WarPhaseChanger* WPC) ;
    virtual string getPhase();
};

#endif