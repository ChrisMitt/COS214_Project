//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Negotiate.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Negotiate::Negotiate() : WarStrategy()
{
    this->startegy_name="Negotiate";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

Negotiate::~Negotiate()
{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Negotiate::RulesofEngagement()
{
    cout<<"Country is Negotiating"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////