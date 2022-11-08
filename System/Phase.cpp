//
// Created by chris on 2022/11/07.
//

#include "Phase.h"
#include "PhasesofWar.h"
#include "Alliance.h"
#include "Country.h"
#include "WarTheatre.h"

Country* UN[12]; // Array of countries in UN
list<Alliance*> allAlliances;// List of all alliances
class PhasesofWar* p;

Phase::~Phase() {
}

Phase1::Phase1() {
    cout<< endl << getPhase() << endl <<endl;

    cout<<"Welcome to the War Engine. Please decide what the dispute is:" <<endl;
    cout<<"[1] - Land Dispute \n[2] - Political Differences \n[3] - World Domination"<<endl;
    int val = 0;
    cin>> val;

    switch (val) {
        case 1:
            cout<< "You have chosen Land Dispute. Prepare to form alliances" <<endl;
            break;

        case 2:
            cout<< "You have chosen Political Differences. Prepare to form alliances" <<endl;
            break;

        case 3:
            cout<< "You have chosen World Domination. Prepare to form alliances" <<endl;
            break;
    }


}

void Phase1::changePhase(PhasesofWar *p, bool success) {
    p->setPhase(new Phase2(true));

}

string Phase1::getPhase() {
    return "Phase 1 - Dispute";
}

Phase2::Phase2(bool loop){
    //Populating countries array
    string names[12] = {"Afghanistan", "China", "France", "Germany", "Japan", "North Korea", "Norway", "Russia", "South Korea", "United Kingdom", "United States of America", "Zimbabwe"};
    for (int i = 0; i < 12; i++)
    {
        UN[i] = new Country();
        UN[i] -> setName(names[i]);
        UN[i] -> setEntities(names[i]);//set the base armies for the countries
        //UN[i] -> printArmy();
    }

    if(loop == true) {
        cout << endl << getPhase() << endl;
        cout << endl << "Create the first alliance:" << endl;
        createAlliance();

        cout << endl << "Create the second alliance:" << endl;
        createAlliance();

        cout << endl << "The alliances have been formed! Prepare for war!" << endl;
        this->changePhase(p, true);
    }
    else{
        cout << endl << getPhase() << endl;
        cout<< "The alliances couldn't resolve their problems and new alliances must be reformed now." <<endl;
        editAlliances();
        this->changePhase(p, true);
    }
}

void Phase2::changePhase(PhasesofWar *p, bool success) {
    p->setPhase(new Phase3);
}

string Phase2::getPhase() {
    return "Phase 2 - Forming Alliances";
}

Phase3::Phase3() {
    //war theatre conflict
    cout<< endl << getPhase() <<endl;
    cout<< endl << "The Battle Begins!" <<endl;
    bool firstBattle = true;
    /** Start battle will happen here.
    startBattle(firstBattle);
     **/

    cout<< endl << "The Battle has ended." <<endl;

    this->changePhase(p, true);
}

void Phase3::changePhase(PhasesofWar *p, bool success) {
    p->setPhase(new Phase4);
}

string Phase3::getPhase() {
    return "Phase 3 - Conflict";
}

Phase4::Phase4(){
    cout<< endl << getPhase() <<endl;
    showUN();

    cout<< endl << "Resource Management: " <<endl;
    for(int i=0; i<12; i++){
        if(UN[i]->getAllianceState() == 1){
            cout<< UN[i]->getName() << " is managing its resources and creating new units." <<endl;
            ResourceManagement(UN[i]);
        }
    }

    cout<< endl << "Alliances are finished with their Resource Management. \nThey have also tried to negotiate a ceasefire. Were they successful? \n[Y/N]" <<endl;
    char in;
    cin>>in;

    if(in == 'Y'){
        cout<< "Ceasefire is established! Proceeding to Diplomacy!" <<endl;
        this->changePhase(p, true);
    }
    else{
        cout<< "Ceasefire is not recognised. The war continues." <<endl;
        this->changePhase(p, false);
    }

}

void Phase4::changePhase(PhasesofWar *p, bool success) {
    if(success) {
        p->setPhase(new Phase5);
    }
    else{
        p->setPhase(new Phase3);
    }
}

string Phase4::getPhase() {
    return "Phase 4 - Post Conflict";
}

Phase5::Phase5() {
    cout << endl << getPhase() << endl;
    cout<< endl << "The Alliances are now engaging in diplomacy in hopes of ending the war." <<endl;
    cout<< "[1] - The alliances come to a peaceful solution. \n[2] - The alliances keep fighting and the war is escalated." <<endl;
    int in;
    cin>>in;

    if(in == 1){
        this->changePhase(p, true);
    }
    else{
        this->changePhase(p, false);
    }
}

void Phase5::changePhase(PhasesofWar *p, bool success) {
    if(success) {
        cout<< endl << "Diplomacy prevails! The War is Over!" <<endl;
        p->setPhase(0);
    }
    else{
        cout<< endl << "The was has escalated!" <<endl;
        p->setPhase(new Phase2(false));
    }
}

string Phase5::getPhase() {
    return "Phase 5 - Diplomacy";
}

void Phase2::createAlliance() {
    string aName;
    int countryLoop = -1;
    cout << "---------- Create an Alliance ----------\nAlliance Name: ";
    cin >> aName;
    allAlliances.push_back(new Alliance(aName));
    while (countryLoop != 0)
    {
        cout << "What country would you like to add to "<< aName << "?\n";
        cout << "[0] Stop adding countries\n";
        for (int i = 0; i < 12; i+=6)
        {
            cout << "["<< (i+1) << "] " << UN[i]->getName() << "\t["<< (i+2) << "] " << UN[i+1]->getName()
                 << "\t["<< (i+3) << "] " << UN[i+2]->getName()<< "\t["<< (i+4) << "] " << UN[i+3]->getName()
                 << "\t["<< (i+5) << "] " << UN[i+4]->getName()<< "\t["<< (i+6) << "] " << UN[i+5]->getName()<< endl;
        }
        cin >> countryLoop;
        if (countryLoop != 0)
        {
            allAlliances.back()->addCountry(UN[countryLoop-1]);
        }
    }
}

/**void Phase3::startBattle(bool firstBattle){
    if(firstBattle){
        allAlliances.push_back(new Alliance("Royal soldiers"));
        allAlliances.push_back(new Alliance("United troops"));
        allAlliances.front()->addCountry( UN[1] );
        allAlliances.front()->addCountry( UN[2] );
        allAlliances.back()->addCountry( UN[3] );
        allAlliances.back()->addCountry( UN[4] );
        printAlliances();
    }

    WarTheatre* w = new WarTheatre( allAlliances );
    w->battle();
    delete w;
}

 **/

void Phase3::printAlliances()
{
    for (auto it = allAlliances.begin(); it != allAlliances.end(); ++it)
    {
        (*it)->showAlliance() ;
        cout << endl;
    }
}

void Phase4::showUN()
{
    cout << endl;
    cout.width(15); cout << left << "INDEX";
    cout.width(35); cout << left << "COUNTRY";
    cout.width(20); cout << left << "ALLIANCE";
    cout << left << "STATE\n";

    for (int i = 0; i < 12; i++)
    {
        cout.width(15); cout << left << i+1;
        cout.width(35); cout << left << UN[i] -> getName();
        if (UN[i]->getAllianceState() == 1)
        {
            cout.width(20); cout << left << UN[i]->getSubject()->getName();
        }
        else
        {
            cout.width(20); cout << left << "No alliance";
        }
        cout << left << UN[i]->getState()->getStateString()<<endl;
    }
}

void Phase4::createResources(Country* co) {

    int unitType = (rand()%4)+1;
    int val = co->resources;
    ResourceManagement* rs = new UnitProducer(60, 4);
    rs->add(new UnitProducer(40, 3));
    rs->add(new UnitProducer(20, 2));
    rs->add(new UnitProducer(2, 1));

    int ret = rs->createUpgradedUnit(unitType, co);
    int choice = (rand()%1);


    switch (ret) {
        case 0:
            break;
            {case 1:
                    Soldier* upgradedSoldier;
                if(choice==1){
                    upgradedSoldier = new Soldier("//", "Deployed", new ExtraHealth(new Research));
                }
                else{
                    upgradedSoldier = new Soldier("Heavy", "Deployed", new ExtraDamage(new Research));
                }
                co->soldiers.push_back(upgradedSoldier);
                break;}

            {case 2:
                    Tank* upgradedTank;
                if(choice==1){
                    upgradedTank = new Tank("Tiger", "Deployed", new ExtraHealth(new Research));
                }
                else{
                    upgradedTank = new Tank("Tiger", "Deployed", new ExtraDamage(new Research));
                }
                co->tanks.push_back(upgradedTank);
                break;}

            {case 3:
                    Plane* upgradedPlane;
                if(choice==1){
                    upgradedPlane = new Plane("Bomber", "Deployed", new ExtraHealth(new Research));
                }
                else{
                    upgradedPlane = new Plane("Fighter", "Deployed", new ExtraDamage(new Research));
                }
                co->planes.push_back(upgradedPlane);
                break;}

            {case 4:
                    Ship* upgradedShip;
                if(choice==1){
                    upgradedShip = new Ship("Cruiser", "Deployed", new ExtraHealth(new Research));
                }
                else{
                    upgradedShip = new Ship("Destroyer", "Deployed", new ExtraDamage(new Research));
                }
                co->ships.push_back(upgradedShip);
                break;}
    }
}

void Phase2::editAlliances()
{
    int editLoop = -1;
    int innerLoop = -1;
    int add = -1;
    int rem = -1;
    int stateLoop = -1;
    while (editLoop != 0)
    {
        editLoop = -1;
        innerLoop = -1;
        add = -1;
        rem = -1;
        stateLoop = -1;

        cout << "Which alliance would you like to edit?\n";
        int num = 1;
        for (auto it = allAlliances.begin(); it != allAlliances.end(); ++it)
        {
            cout << "[" << num << "] " << (*it)->getName() << endl;
            num ++;
        }
        cout << "[0] Stop editing\n";
        cin >> editLoop;
        if (editLoop != 0)
        {
            list<Alliance*>::iterator itr = allAlliances.begin();
            advance(itr, (editLoop-1));
            while (innerLoop != 0)
            {
                cout << "What would you like to edit in " << (*itr)->getName() << "?\n[1] Add a country\n[2] Remove a country\n[3] Change alliance state\n[0] Stop editing this alliance\n";
                cin >> innerLoop;
                if (innerLoop != 0)
                {
                    if (innerLoop == 1)
                    {
                        while (add != 0)
                        {
                            cout << "Which country would you like to add to " << (*itr)->getName() << "?\n";
                            cout << "[0] Stop adding countries\n";
                            for (int i = 0; i < 12; i+=6)
                            {
                                cout << "["<< (i+1) << "] " << UN[i]->getName() << "\t["<< (i+2) << "] " << UN[i+1]->getName()
                                     << "\t["<< (i+3) << "] " << UN[i+2]->getName()<< "\t["<< (i+4) << "] " << UN[i+3]->getName()
                                     << "\t["<< (i+5) << "] " << UN[i+4]->getName()<< "\t["<< (i+6) << "] " << UN[i+5]->getName()<< endl;
                            }
                            cin >> add;
                            if (add != 0)
                            {
                                (*itr)->addCountry(UN[add-1]);
                            }
                        }
                    }
                    else if (innerLoop == 2)
                    {
                        while (rem != 0)
                        {
                            if (rem != 0)
                            {
                                cout << "\nWhich country would you like to remove from " << (*itr)->getName() << "?\n";
                                (*itr)->showAlliance();
                                cout << "[0] Don't remove a country\n";
                                cin >> rem;
                                if (rem != 0)
                                {
                                    (*itr)->removeCountry(rem);
                                }
                            }
                        }
                    }
                    else if (innerLoop == 3)
                    {
                        cout << "\nWhat state would you like to change " << (*itr)->getName() << " to?\n";
                        cout << "[1] Peace\n[2] War\n[3] Negotiating\n[0] Don't change state\n";
                        cin >> stateLoop;
                        if (stateLoop == 1)
                        {
                            (*itr)->setState(new peaceState());
                        }
                        else if (stateLoop == 2)
                        {
                            (*itr)->setState(new warState());
                        }
                        else if (stateLoop == 3)
                        {
                            (*itr)->setState(new negotiatingState());
                        }
                    }
                }
            }
        }
    }
}

