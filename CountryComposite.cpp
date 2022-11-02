#include "CountryComposite.h"

CountryComposite::CountryComposite(/* args */)
{
}

CountryComposite::~CountryComposite()
{
}

void CountryComposite::fight(){
    vector<CountryObserver>::iterator it;
    for(it=children.begin(); it!=children.end(); it++){
        (*it)->print();
    }
}

void CountryComposite::add(CountryObserver* c){
    children.push_back(c);
}