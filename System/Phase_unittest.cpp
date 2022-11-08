#include <limits.h>
#include "Phase.h"
#include "gtest/gtest.h"

// Tests getPhase().
// Tests return vals of getPhase
// Testing the precondition
// Testing the postcondition: Returns valid string when changing phase
namespace{
    TEST(PhaseTest, correctPhase) {
        PhasesofWar* phase = new PhasesofWar();
        EXPECT_EQ("Phase 1 - Dispute", phase->getPhase());
        phase->changePhase(true);
        EXPECT_EQ("Phase 2 - Forming Alliances", phase->getPhase());
        phase->changePhase(true);
        EXPECT_EQ("Phase 3 - Conflict", phase->getPhase());
        phase->changePhase(true);
        EXPECT_EQ("Phase 4 - Post Conflict", phase->getPhase());
        phase->changePhase(true);
        EXPECT_EQ("Phase 5 - Diplomacy", phase->getPhase());
    }

    TEST(PhaseTest, notNullPhase) {
        Phase1* p1 = new Phase1;
        if ( p1==NULL ) {
            throw std::invalid_argument("Phase 1 has a bad contructor"); 
        } 
    }
}