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
*  @brief A Phases1 class. ConcreteState Class for the StatePattern .
*/
class Phase1 : public PhasesofWar
{
    private:
        /* data */
    public:
        
        /**
        * @brief A constructor.
        * Default Phase1 constructor.
        */
        Phase1();

        /**
        * @brief A destructor.
        * Phase1 destructor.
        */
        ~Phase1();

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
