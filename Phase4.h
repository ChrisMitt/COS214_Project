#ifndef PHASE4_H
#define PHASE4_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

/**
*  A Phases4 class. ConcreteState Class for the StatePattern .
*/

class Phase4 : public PhasesofWar
{
private:
    /* data */
public:

    /**
    * A constructor.
    * Default Phase4 constructor.
    */
    Phase4();

    /**
    * A destructor.
    * Phase4 destructor.
    */
    ~Phase4();

    /**
    * A virtual member.
    * @see Phase4()
    * @see ~Phase4()
    * @see getPhase()
    * @param WPC  a pointer argument
    */
    virtual void changePhase(WarPhaseChanger* WPC) ;

    /**
    * A pure virtual member.
    * @see changePhase()
    * @return A string 
    */
    virtual string getPhase();
};

#endif