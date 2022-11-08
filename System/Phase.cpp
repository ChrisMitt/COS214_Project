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

Phase::~Phase() {
}

string Phase::dispute = "";
int Phase::result = -1;

Phase1::Phase1() {
    cout<< endl << getPhase() << endl <<endl;

    cout<<"Welcome to the War Engine. Please decide what the dispute is:" <<endl;
    cout<<"[1] - Land Dispute \n[2] - Political Differences \n[3] - Wolrd Domination"<<endl;
    int val = 0;
    cin>> val;

    switch (val) {
        case 1:
            cout<< "You have chosen Land Dispute. Prepare to form alliances" <<endl;
            dispute="land";
            break;

        case 2:
            cout<< "You have chosen Political Differences. Prepare to form alliances" <<endl;
            dispute="politics";
            break;

        case 3:
            cout<< "You have chosen World Domination. Prepare to form alliances" <<endl;
            dispute="domination";
            break;
    }


}

void Phase1::changePhase(PhasesofWar *p) {
    p->setPhase(new Phase2);

}

string Phase1::getPhase() {
    return "Phase 1 - Dispute";
}

Phase2::Phase2(){
    system("clear");
    //Populating countries array
    string names[12] = {"Afghanistan", "China", "France", "Germany", "Japan", "North Korea", "Norway", "Russia", "South Korea", "United Kingdom", "United States of America", "Zimbabwe"};
    for (int i = 0; i < 12; i++)
    {
        UN[i] = new Country();
        UN[i] -> setName(names[i]);
        UN[i] -> setEntities(names[i]);//set the base armies for the countries
        UN[i] -> printArmy();
    }

    cout<< endl << getPhase()<<endl;
    system("clear");
    cout<< endl << "Create the first alliance:" <<endl;
    createAlliance();

    cout<< endl << "Create the second alliance:" <<endl;
    createAlliance();

    cout<< endl << "The alliances have been formed! Prepare for war!" <<endl;
}

void Phase2::changePhase(PhasesofWar *p) {
    p->setPhase(new Phase3);
}

string Phase2::getPhase() {
    return "Phase 2 - Forming Alliances";
}

Phase3::Phase3() {
    system("clear");
    //war theatre conflict
    cout<< endl << getPhase() <<endl;
    cout<< endl << "The Battle Begins!" <<endl;
    bool firstBattle = true;
    /** Start battle will happen here.
    startBattle(firstBattle);
     **/
    WarTheatre* w = new WarTheatre( allAlliances );
    result = w->battle();
    delete w;

    cout<< endl << "The Battle has ended." <<endl;
}

void Phase3::changePhase(PhasesofWar *p) {
    p->setPhase(new Phase4);
}

string Phase3::getPhase() {
    return "Phase 3 - Conflict";
}

Phase4::Phase4(){
    cout<< endl << getPhase() <<endl;
    showUN();
}

void Phase4::changePhase(PhasesofWar *p) {
    p->setPhase(new Phase5);
}

string Phase4::getPhase() {
    return "Phase 4 - Post Conflict";
}

Phase5::Phase5(){
    cout<< endl << getPhase() <<endl;
    Alliance* winner;
    Alliance* loser;
    if(result==0){
        winner = allAlliances.front();
        loser = allAlliances.front();
    }else if(result==1){
        winner = allAlliances.back();
        loser = allAlliances.back();
    }

    if(dispute=="land"){
        cout<<winner->getName()<<" won the war and chose to colonise "<<loser->getCountryList().front()->getName()<<endl;
    }
    if(dispute=="politics"){
        cout<<winner->getName()<<" won the war, and overruled the dictatorship of "<<loser->getCountryList().front()->getName()<<endl;
    }
    if(dispute=="domination"){
        cout<<winner->getName()<<" won the war and proved that they are powerful "<<endl;
    }
    cout<<"\n ---- end of war simulator ----\n";
}

void Phase5::changePhase(PhasesofWar *p) {
    p->setPhase(0);
}

string Phase5::getPhase() {
    return "Phase 5 - Negotiations";
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

