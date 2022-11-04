//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASE2_H
#define PHASE2_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PhasesofWar.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  A Phases2 class. ConcreteState Class for the StatePattern .
*/
class Phase2 : public PhasesofWar
{
    private:
        /* data */
    public:

        /**
        * A constructor.
        * Default Phase2 constructor.
        */
        Phase2();

        /**
        * A destructor.
        * Phase2 destructor.
        */
        ~Phase2();

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