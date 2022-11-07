//
// Created by Rebecca on 2022/10/31.
//
// Edited by Charl on 2022/10/31

#include <iostream>
#include "Country.h"
#include "Alliance.h"
#include "State.h"
#include <list>
#include <iterator>
#include "WarTheatre.h"
using namespace std;

Country* UN[12]; // Array of countries in UN
list<Alliance*> allAlliances;// List of all alliances

void createAlliance()
{
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

void printAlliances()
{
    for (auto it = allAlliances.begin(); it != allAlliances.end(); ++it)
    {
        (*it)->showAlliance() ;
        cout << endl;
    }
}

void editAlliances()
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

void showUN()
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

void startBattle(bool firstBattle){
    if(firstBattle){
        allAlliances.push_back(new Alliance("Royal soldiers"));
        allAlliances.push_back(new Alliance("United troops"));
        allAlliances.front()->addCountry(UN[1]);
        allAlliances.front()->addCountry(UN[2]);
        allAlliances.back()->addCountry(UN[3]);
        allAlliances.back()->addCountry(UN[4]);
        printAlliances();
    }

    WarTheatre* w = new WarTheatre(allAlliances);
    w->battle();
    delete w;
}

int main()
{
    //Populating countries array
    string names[12] = {"Afghanistan", "China", "France", "Germany", "Japan", "North Korea", "Norway", "Russia", "South Korea", "United Kingdom", "United States of America", "Zimbabwe"};
    for (int i = 0; i < 12; i++)
    {
        UN[i] = new Country();
        UN[i] -> setName(names[i]);
        UN[i] -> setEntities(names[i]);//set the base armies for the countries
        UN[i] -> printArmy();
    }
    
    
    cout << "Welcome to the war simulator!\n";
    
    int input = -1;
    bool firstBattle = true;
    while (input != 0)
    {
        if (input == 1)
        {
            printAlliances();
        }
        else if (input == 2)
        {
            createAlliance();
        }
        else if (input == 3)
        {
            editAlliances();
        }
        else if (input == 4)
        {
            showUN();
        }else if (input == 5)
        {
            startBattle(firstBattle);
            firstBattle = false;
        }
        cout << "\nWhat would you like to do?\n[1] View alliances\n[2] Create a new alliance\n[3] Edit an alliance\n[4] View UN\n[5] Start battle\n[0] Exit\n";
        cin >> input;
    }
    
    return 0;
}