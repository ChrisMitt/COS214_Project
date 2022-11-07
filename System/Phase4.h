//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASE4_H
#define PHASE4_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PhasesofWar.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  @brief A Phases4 class. ConcreteState Class for the StatePattern .
*/
class Phase4 : public PhasesofWar
{
    private:
        /* data */
    public:

        /**
        * @brief A constructor.
        * Default Phase4 constructor.
        */
        Phase4();

        /**
        * @brief A destructor.
        * Phase4 destructor.
        */
        ~Phase4();

        /**
        * @brief A virtual member.
        * @param WPC  a pointer argument
        */
        virtual void changePhase(WarPhaseChanger* WPC) ;

        /**
        * @brief A pure virtual member.
        * @return A string 
        */
        virtual string getPhase();
};

#endif