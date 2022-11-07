#pragma once

#include "CountryObserver.h"
#include <vector>

using namespace std;

class CountryComposite:public CountryObserver
{
private:
    vector<CountryObserver*> children;
public:
    CountryComposite(/* args */);
    ~CountryComposite();
    void fight();
    void add(CountryObserver* c);
};
