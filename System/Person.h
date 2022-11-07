//
// Created by chris on 2022/10/31.
//
/**
 *
 */
#ifndef COS214_PROJECT_PERSON_H
#define COS214_PROJECT_PERSON_H

#include <string>
#include "Vehicle.h"
#include "UnitBackup.h"
#include "Decorator.h"

class Vehicle;

using namespace std;
/**
 * @brief a person class. an abstract product for the personfactory class
 * an abtract product class for the abtract factory pattern
 */
class Person {
public:
/**
 * @brief Construct a new Person object
 * 
 */
    Person();
    /**
     * @brief Construct a new Person object
     * @param string a string argument
     * @param string a  string argument
     * @param h 
     */
    Person(string, string, int h=100);
    /**
     * @brief Construct a new Person object
     * @param Person a a pointer argument
     */
    Person(Person*);
    /**
     * @brief Get the Type object
     * 
     * @return string 
     */
    string getType();
    /**
     * @brief Get the State object
     * 
     * @return string 
     */
    string getState();
    /**
     * @brief Get the Health object
     * 
     * @return int 
     */
    int getHealth();
    /**
     * @brief Set the Health object
     * @param int
     */
    void setHealth(int);
    /**
     * @brief Get the Status object
     * 
     * @return Status* 
     */
    Status* getStatus();
    /**
     * @brief a normal member
     * @param UnitBackup*
     */
    void restore(UnitBackup*);
    /**
     * @brief Destroy the Person object
     * 
     */
    virtual ~Person();

protected:
/**
 * @brief a pure virtual argument
 * 
 */
    virtual void interact() = 0;
    /**
     * @brief a pure virtual argument
     * 
     * @return Person* 
     */
    virtual Person* clone() = 0;

protected:
/**
 * @brief a protected variable
 * a string object
 */
    string type;
    /**
 * @brief a protected variable
 * a string object
 */
    string state;
    /**
 * @brief a protected variable
 * an integer object
 */
    int health;
    /**
 * @brief a protected variable
 * a Status pointer object
 */
    Status* status;
};

/**
 * @brief A soldier class. a product of the person class
 * 
 */
class Soldier : public Person{
public:
/**
 * @brief Construct a new Soldier object
 * 
 */
    Soldier();
    /**
     * @brief Construct a new Soldier object
     * @param string
     * @param string
     * @param  RnD*
     */
    Soldier(string, string, RnD*);
    /**
     * @brief Construct a new Soldier object
     * @param string
     * @param string@param string
     * @param string
     * @param h 
     * @param d 
     */
    Soldier(string, string, int h=100, int d=25);
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int attack();
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int defend();
    /**
     * @brief a normal member
     * 
     * @return int 
     */
    int research();
    /**
     * @brief a virtual memeber
     * 
     */
    virtual void interact();
    /**
     * @brief a virtual member
     * 
     * @return Soldier* 
     */
    virtual Soldier* clone();
    /**
     * @brief a normal member
     * 
     * @return UnitBackup* 
     */
    UnitBackup* makeBackup();
    /**
     * @brief Get the Health object
     *
     * @return int
     */
    int getHealth();
    /**
     * @brief Get the Damage object
     * 
     * @return int 
     */
    int getDamage();
    /**
     * @brief a normal member
     * 
     * @param victim 
     */
    void doDamage(Soldier* victim);
    /**
     * @brief a normal agurment
     *
     * @param amount
     */
    void takeDamage(int amount);

private:
/**
 * @brief a private variable
 * an integer variable
 * 
 */
    int damage;
    /**
     * @brief a private variable
     * an RnD* pointer variable
     * 
     */
    RnD* upgrade;
    /**
     * @brief a private variable
     * an int pointer variable
     *
     */
};


/**
 * @brief a medic class. a product class of the person class
 * 
 */
class Medic : public Person{
public:
/**
 * @brief Construct a new Medic object
 * 
 */
    Medic();
    /**
     * @brief Construct a new Medic object
     * @param string
     * @param string
     * @param h 
     */
    Medic(string, string, int h=100);
    /**
     * @brief a normal member
     * @param Person*
     */
    void heal(Person*);
    /**
     * @brief a virtual member
     * 
     */
    virtual void interact();
    /**
     * @brief a virtual member
     * 
     * @return Medic* 
     */
    virtual Medic* clone();
    /**
     * @brief Get the Memento object
     * 
     * @return UnitBackup* 
     */
    UnitBackup* getMemento();
    /**
     * @brief Set the Memento object
     * 
     */
    void setMemento(UnitBackup*);

private:
/**
 * @brief a private variable
 * a  UnitBackup pointer varibale
 * 
 */
    UnitBackup* memento;
};


/**
 * @brief a Mechanic class. a product of the person class
 * 
 */
class Mechanic : public Person{
public:
/**
 * @brief Construct a new Mechanic object
 * 
 */
    Mechanic();
    /**
     * @brief Construct a new Mechanic object
     * @param string
     * @param string
     * @param h 
     */
    Mechanic(string, string, int h=100);
    /**
     * @brief a normal member
     * @param Vehicle
     */
    void repair(Vehicle*);
    /**
     * @brief a virtual member
     * 
     */
    virtual void interact();
    /**
     * @brief a virtual member
     * 
     * @return Mechanic* 
     */
    virtual Mechanic* clone();
    /**
     * @brief Get the Memento object
     * 
     * @return UnitBackup* 
     */
    UnitBackup* getMemento();
    /**
     * @brief Set the Memento object
     * 
     */
    void setMemento(UnitBackup*);

private:
/**
 * @brief a private variable
 * a UnitBackup pointer variable
 */
    UnitBackup* memento;
};

#endif //COS214_PROJECT_PERSON_H
