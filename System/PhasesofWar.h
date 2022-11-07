//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASESOFWAR_H
#define PHASESOFWAR_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "WarPhaseChanger.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

class WarPhaseChanger;

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
*  @brief A PhasesofWar class. State Class for the StatePattern .
*/
class PhasesofWar
{
    private:
        /* data */
        
    public:

        /**
        * @brief A constructor.
        * Default PhasesofWar constructor.
        */
        PhasesofWar();

        /**
        * @brief A destructor.
        * virtual PhasesofWar destructor.
        */
        virtual ~PhasesofWar();

        /**
        * @brief A pure virtual member.
        * @param WPC  a pointer argument
        */
        virtual void changePhase(WarPhaseChanger* WPC) = 0;

        /**
        * @brief A pure virtual member.
        * @return A string 
        */
        virtual string getPhase() = 0;

};

#endif