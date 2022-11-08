#pragma once

#include "CountryObserver.h"
#include <vector>

using namespace std;

/**
 * @brief CountryComposite class. a Composite class for the composite pattern
 * 
 */
class CountryComposite:public CountryObserver
{
private:
/**
 * @brief a vector of CountryObserves 
 * 
 */
    vector<CountryObserver*> children;
public:
/**
 * @brief construct a new CountryComposite object
 * 
 */
    CountryComposite(/* args */);
    /**
     * @brief Destroy the Country Composite object
     * 
     */
    ~CountryComposite();
    /**
     * @brief a normal member
     * 
     */
    void fight();
    /**
     * @brief a normal member
     * 
     * @param c 
     */
    void add(CountryObserver* c);
};
