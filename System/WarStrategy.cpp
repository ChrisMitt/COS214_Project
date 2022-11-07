//
// Created by Akani Hlungwani
//

////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "WarStrategy.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////

WarStrategy::WarStrategy(bool s)
{
    status=s;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

WarStrategy::~WarStrategy()
{}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

string WarStrategy::getName()
{
    return strategy_name;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool WarStrategy::getStatus()
{
    return status;
}  

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void WarStrategy::setStatus(bool s)
{
    status=s;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////