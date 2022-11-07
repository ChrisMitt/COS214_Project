//
// Created by Akani Hlungwani
//

#include "PhasesofWar.h"

using namespace std;

PhasesofWar::PhasesofWar() {
    phase = new Phase1();
}

PhasesofWar::~PhasesofWar()
{
   delete phase;
    phase = 0;
}

void PhasesofWar::changePhase() {
    phase->changePhase(this);
}

string PhasesofWar::getPhase() {
    return phase->getPhase();
}

void PhasesofWar::setPhase(Phase *p) {
    delete phase;
    phase = p;
}