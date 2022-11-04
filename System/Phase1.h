//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASE1_H
#define PHASE1_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PhasesofWar.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  A Phases1 class. ConcreteState Class for the StatePattern .
*/
class Phase1 : public PhasesofWar
{
    private:
        /* data */
    public:
        
        /**
        * A constructor.
        * Default Phase1 constructor.
        */
        Phase1();

        /**
        * A destructor.
        * Phase1 destructor.
        */
        ~Phase1();

        /**
        * A virtual member.
        * @see Phase1()
        * @see ~Phase1()
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
