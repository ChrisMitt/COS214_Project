//
// Created by chris on 2022/11/07.
//

#include <iostream>
#include "PhasesofWar.h"

using namespace std;

int main(){

    PhasesofWar* phase = new PhasesofWar();
    bool loop = true;
    while(loop){
        phase->changePhase(true);
        loop = false;
        delete phase;
    }

    return 0;
}
