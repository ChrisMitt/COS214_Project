//
// Created by chris on 2022/11/07.
//

#include <iostream>
#include "PhasesofWar.h"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv){

    PhasesofWar* phase = new PhasesofWar();
    bool loop = true;
    while(loop){
        phase->changePhase(true);
        loop = false;
        delete phase;
    }


    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
