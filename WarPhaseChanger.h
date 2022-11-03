#ifndef WARPHASECHANGER_H
#define WARPHASECHANGER_H

#include "PhasesofWar.h"
#include "WarStrategy.h"

#include <iostream>

using namespace std;

class PhasesofWar;


/**
 *  A WarPhaseChanger class. Context Class for both the Strategy and State Pattern .
 */

class WarPhaseChanger
{
    private:
       
       /** 
       * a public variable.
       * A pointer to a PhasesofWar Object/Class.
       */
        PhasesofWar* War_phase;
        
       /** 
       * a public variable.
       * A pointer to a WarStrategy Object/Class.
       */
        WarStrategy* CountryStrat;
    public:

       /**
       * A constructor.
       * Default WarPhaseChanger constructor.
       */
        WarPhaseChanger();

       /**
       * A destructor.
       * WarPhaseChanger destructor.
       */
        ~WarPhaseChanger();

       /**
       * a normal member taking one arguments and sets the WarStrategy pointer.
       * @param Strategy a pointer argument.
       * @see WarPhaseChanger()
       * @see ~WarPhaseChanger()
       * @see Engage()
       * @see setPhase()
       * @see requestPhase()
       * @see getPhase()
       */
        void setStrategy(WarStrategy* Strategy);

       /**
       *  a normal member taking one arguments and sets the WarStrategy pointer.
       * @param Strategy a pointer argument.
       * @see setStrategy()
       */
        void Engage();  

       /**
       *  a normal member taking one arguments and sets the PhasesofWar pointer.
       * @param phase a pointer argument.
       */
        void setPhase(PhasesofWar* phase);

       /**
       *  a normal member that changes the PhasesofWar.
       */
        void requestPhase();

       /**
       *  a normal member that return that type of Phase.
       *  @return The String name of the Phase
       */
        string getPhase();

};

#endif