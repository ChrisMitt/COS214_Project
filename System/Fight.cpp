//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Fight.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Fight::Fight() : WarStrategy()
{
    this->startegy_name="Fight";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Fight::~Fight()
{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Fight::RulesofEngagement()
{
    cout<<"Country is Fighting to defend its territory"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////