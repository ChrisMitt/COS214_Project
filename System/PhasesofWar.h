#ifndef PHASESOFWAR_H
#define PHASESOFWAR_H

#include "WarPhaseChanger.h"
#include <iostream>

class WarPhaseChanger;

/**
*  A PhasesofWar class. State Class for the StatePattern .
*/

class PhasesofWar
{
    private:
        /* data */
        
    public:

        /**
        * A constructor.
        * Default PhasesofWar constructor.
        */
        PhasesofWar();

        /**
        * A destructor.
        * virtual PhasesofWar destructor.
        */
        virtual ~PhasesofWar();

        /**
        * A pure virtual member.
        * @see PhasesofWar()
        * @see ~PhasesofWar()
        * @see getPhase()
        * @param WPC  a pointer argument
        */
        virtual void changePhase(WarPhaseChanger* WPC) = 0;

        /**
        * A pure virtual member.
        * @see changePhase()
        * @return A string 
        */
        virtual std::string getPhase() = 0;

};

#endif