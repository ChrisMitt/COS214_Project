//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASE5_H
#define PHASE5_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PhasesofWar.h"
#include <iostream>
////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  A Phases5 class. ConcreteState Class for the StatePattern .
*/
class Phase5 : public PhasesofWar
{
    private:
        /* data */
    public:

        /**
        * A constructor.
        * Default Phase5 constructor.
        */
        Phase5();

        /**
        * A destructor.
        * Phase5 destructor.
        */
        ~Phase5();

        /**
        * A virtual member.
        * @param WPC  a pointer argument
        */
        virtual void changePhase(WarPhaseChanger* WPC) ;

        /**
        * A pure virtual member.
        * @return A string 
        */
        virtual string getPhase();
};

#endif