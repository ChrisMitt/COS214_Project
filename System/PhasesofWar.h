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
*  @brief A PhasesofWar class. State Class for the StatePattern .
*/
class PhasesofWar{
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
        * @brief A void member.
        */
        void changePhase();

        /**
        * @brief A void member.
        * @return A string 
        */
        string getPhase();

    /**
    * @brief A void member.
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