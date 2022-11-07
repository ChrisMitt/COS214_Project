//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef PHASESOFWAR_H
#define PHASESOFWAR_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Phase.h"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

class Phase;

////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
*  A PhasesofWar class. State Class for the StatePattern .
*/
class PhasesofWar{
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
        * A void member.
        */
        void changePhase();

        /**
        * A void member.
        * @return A string 
        */
        string getPhase();

    /**
    * A void member.
    * @param p  a pointer argument
    */
    void setPhase(Phase* p);

private:
    /**
     * @brief A Phase pointer object
     *
     */
    Phase* phase;

};

#endif