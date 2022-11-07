#include "CountryComposite.h"
#include <vector>

using namespace std;

CountryComposite::CountryComposite(/* args */)
{
}

CountryComposite::~CountryComposite()
{
}

void CountryComposite::fight(){
    vector<CountryObserver*>::iterator it;
    for(it=children.begin(); it!=children.end(); it++){
        cout << name << " is now fighting, for alliance: " << subject->getName() << endl;
        (*it)->fight();
    }
}

void CountryComposite::add(CountryObserver* c){
    children.push_back(c);
}