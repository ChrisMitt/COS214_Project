//
// Created by chris on 2022/11/03.
//

#ifndef COS214_PROJECT_DECORATOR_H
#define COS214_PROJECT_DECORATOR_H

using namespace std;
class RnD {
public:
    virtual int research() = 0;
    virtual ~RnD(){};
};

class Research : public RnD{
public:
    int research();
    virtual ~Research(){};
};

class Upgrade : public RnD{
public:
    virtual int research();
    Upgrade(RnD* up);
    string upgradeType;
    virtual ~Upgrade();

private:
    RnD* newUpgrade;
};

class ExtraDamage : public Upgrade{
public:
    ExtraDamage(RnD*);
    string getType();
    int research();
};

class ExtraHealth: public Upgrade{
public:
    ExtraHealth(RnD*);
    string getType();
    int research();

};


#endif //COS214_PROJECT_DECORATOR_H
