#pragma once

#include <string>
#include <iostream>
#include "Squad.h"

using namespace std;

//Director
class SquadBuilder;
class ArmyGeneral
{
private:
    SquadBuilder* builder;
public:
    ArmyGeneral( SquadBuilder*b );
    ~ArmyGeneral();
    void construct(string squadType);
};

//Builder
class SquadBuilder{
protected:

public:
    virtual void addGroundUnits();
    virtual void addAirUnits();
    virtual void addNavyUnits();
};

//ConcreteBuilder
class ConcreteSquadBuilder:public SquadBuilder{
protected:
    Squad* squad;
    Alliance* a;
public:
    ConcreteSquadBuilder(Alliance* alliance);
    ~ConcreteSquadBuilder();
    void addGroundUnits();
    void addAirUnits();
    void addNavyUnits();
    Squad* getResult();
};