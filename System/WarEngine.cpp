//
// Created by chris on 2022/11/07.
//

#include <iostream>
#include "PhasesofWar.h"

using namespace std;

int main(){

    PhasesofWar* phase = new PhasesofWar();
    while(true){
        phase->changePhase(true);
    }

    return 0;
}
