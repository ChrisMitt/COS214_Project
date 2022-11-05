//
// Created by chris on 2022/11/03.
//

#ifndef COS214_PROJECT_DECORATOR_H
#define COS214_PROJECT_DECORATOR_H

using namespace std;
/**
 * @brief a Decorator class. a Decorator for abstractperson and abstractvehicle class.
 * a decorator class for the decorator design pattern
 */
class RnD {
public:
/**
 * @brief a pure virtual member
 * 
 * @return int 
 */
    virtual int research() = 0;
    /**
     * @brief Destroy the RnD object
     * 
     */
    virtual ~RnD(){};
};

/**
 * @brief  aResearch class. A concrete decorator for the decorator pattern(RnD class)
 * 
 */
class Research : public RnD{
public:
/**
 * @brief a norma member
 * 
 * @return int 
 */
    int research();
    /**
     * @brief Destroy the Research object
     * 
     */
    virtual ~Research(){};
};
/**
 * @brief a concrete class for the decoartor pattern(RnD class)
 * 
 */
class Upgrade : public RnD{
public:
/**
 * @brief a normal member
 * 
 * @return int 
 */
    virtual int research();
    /**
     * @brief Construct a new Upgrade object
     * 
     * @param up a n RnD pointer
     */
    Upgrade(RnD* up);
    /**
     * @brief a morma member
     * @return string
     */
    string upgradeType;
    /**
     * @brief Destroy the Upgrade object
     * 
     */
    virtual ~Upgrade();

private:
/**
 * @brief a private variable
 * an RnD pointer
 * 
 */
    RnD* newUpgrade;
};

/**
 * @brief an ExtraDamage class
 * 
 */
class ExtraDamage : public Upgrade{
public:
/**
 * @brief Construct a new Extra Damage object
 * param RnD pointer
 */
    ExtraDamage(RnD*);
    /**
     * @brief Get the Type object
     * 
     * @return string 
     */
    string getType();
    /**
     * @brief 
     * 
     * @return int 
     */
    int research();
};
/**
 * @brief am ExtraHealth class
 * 
 */
class ExtraHealth: public Upgrade{
public:
/**
 * @brief Construct a new Extra Health object
 * 
 */
    ExtraHealth(RnD*);
    /**
     * @brief Get the Type object
     * 
     * @return string 
     */
    string getType();
    /**
     * @brief 
     * 
     * @return int 
     */
    int research();

};


#endif //COS214_PROJECT_DECORATOR_H
