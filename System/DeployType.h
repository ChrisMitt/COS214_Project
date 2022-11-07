#pragma once
#include "Squad.h"

class WarTheatre;
class DeployType
{
protected:
    WarTheatre* w;
    Squad* defenders;
    Squad* attackers;
public:
    DeployType(WarTheatre* w);
    ~DeployType();
    virtual void deploy()=0;
};

class SoldierDeploy:public DeployType
{
public:
    SoldierDeploy(WarTheatre* w);
    ~SoldierDeploy();
    void deploy();
};

class TankDeploy:public DeployType
{
public:
    TankDeploy(WarTheatre* w);
    ~TankDeploy();
    void deploy();
};

class ShipDeploy:public DeployType
{
public:
    ShipDeploy(WarTheatre* w);
    ~ShipDeploy();
    void deploy();
};

class PlaneDeploy:public DeployType
{
public:
    PlaneDeploy(WarTheatre* w);
    ~PlaneDeploy();
    void deploy();
};

