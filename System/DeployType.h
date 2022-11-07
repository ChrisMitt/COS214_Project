#pragma once
#include "Squad.h"

class WarTheatre;

/**
 * @brief a DeployType class.
 * 
 */
class DeployType
{
protected:
    WarTheatre* w;
    Squad* defenders;
    Squad* attackers;
public:
/**
 * @brief Construct a new Deploy Type object
 * 
 * @param w 
 */
    DeployType(WarTheatre* w);
    /**
     * @brief Destroy the Deploy Type object
     * 
     */
    ~DeployType();
    /**
     * @brief a pure virtual member
     * 
     */
    virtual void deploy()=0;
};

/**
 * @brief a soldierDeploy class
 * 
 */
class SoldierDeploy:public DeployType
{
public:
/**
 * @brief Construct a new Soldier Deploy object
 * 
 * @param w 
 */
    SoldierDeploy(WarTheatre* w);
    /**
     * @brief Destroy the Soldier Deploy object
     * 
     */
    ~SoldierDeploy();
    /**
     * @brief a normal member
     * 
     */
    void deploy();
};

/**
 * @brief a TankDeploy class
 * 
 */
class TankDeploy:public DeployType
{
public:
/**
 * @brief Construct a new Tank Deploy object
 * 
 * @param w 
 */
    TankDeploy(WarTheatre* w);
    /**
     * @brief Destroy the Tank Deploy object
     * 
     */
    ~TankDeploy();
    /**
     * @brief a noramal member
     * 
     */
    void deploy();
};

class ShipDeploy:public DeployType
{
public:
/**
 * @brief Construct a new Ship Deploy object
 * 
 * @param w 
 */
    ShipDeploy(WarTheatre* w);
    /**
     * @brief Destroy the Ship Deploy object
     * 
     */
    ~ShipDeploy();
    /**
     * @brief 
     * 
     */
    void deploy();
};

/**
 * @brief a PlaneDeploy class
 * 
 */

class PlaneDeploy:public DeployType
{
public:
/**
 * @brief Construct a new Plane Deploy object
 * 
 * @param w 
 */
    PlaneDeploy(WarTheatre* w);
    /**
     * @brief Destroy the Plane Deploy object
     * 
     */
    ~PlaneDeploy();
    /**
     * @brief a noraml member
     * 
     */
    void deploy();
};

/**
 * @brief a MedicDeploy class
 * 
 */

class MedicDeploy:public DeployType
{
public:
/**
 * @brief Construct a new Medic Deploy object
 * 
 * @param w 
 */
    MedicDeploy(WarTheatre* w);
    /**
     * @brief Destroy the Medic Deploy object
     * 
     */
    ~MedicDeploy();
    /**
     * @brief a noraml member
     * 
     */
    void deploy();
};

class MechanicDeploy:public DeployType
{
public:
/**
 * @brief Construct a new Mechanic Deploy object
 * 
 * @param w 
 */
    MechanicDeploy(WarTheatre* w);
    /**
     * @brief Destroy the Mechanic Deploy object
     * 
     */
    ~MechanicDeploy();
    /**
     * @brief a normal member
     * 
     */
    void deploy();
};

