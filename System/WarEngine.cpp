//
// Created by chris on 2022/11/07.
//

#include <iostream>
#include "PhasesofWar.h"

using namespace std;

int main(){

    PhasesofWar* phase = new PhasesofWar();
    for(int i=0; i<4; i++){
        phase->changePhase();
    }


    return 0;
}
