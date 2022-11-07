//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASE3_H
#define PHASE3_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "PhasesofWar.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
*  @brief A Phases13class. ConcreteState Class for the StatePattern .
*/
class Phase3 : public PhasesofWar
{
    private:
        /* data */
    public:

        /**
        * @brief A constructor.
        * Default Phase3 constructor.
        */
        Phase3();

        /**
        * @brief A destructor.
        * Phase3 destructor.
        */
        ~Phase3();

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