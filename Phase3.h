#ifndef PHASE3_H
#define PHASE3_H

#include "PhasesofWar.h"
#include <iostream>

using namespace std;

/**
*  A Phases13class. ConcreteState Class for the StatePattern .
*/

class Phase3 : public PhasesofWar
{
private:
    /* data */
public:

    /**
    * A constructor.
    * Default Phase3 constructor.
    */
    Phase3();

    /**
    * A destructor.
    * Phase3 destructor.
    */
    ~Phase3();

    /**
    * A virtual member.
    * @see Phase3()
    * @see ~Phase3()
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