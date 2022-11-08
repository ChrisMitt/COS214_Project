#include "ArmyGeneral.h"

ArmyGeneral::ArmyGeneral(SquadBuilder* b)
{
    builder=b;
}

ArmyGeneral::~ArmyGeneral()
{
    delete builder;
}

void ArmyGeneral::construct(string squadType){
    if(squadType=="land"){
        cout<<"1\n";
        builder->addAirUnits();
        cout<<"2\n";
        builder->addGroundUnits();
    }else if(squadType=="sea"){
        builder->addAirUnits();
        builder->addNavyUnits();
    }else if(squadType=="mountains"){
        builder->addAirUnits();
    }
    cout<<"asdfasdf\n";
}



void SquadBuilder::addGroundUnits(){

}

void SquadBuilder::addAirUnits(){

}

void SquadBuilder::addNavyUnits(){

}

ConcreteSquadBuilder::ConcreteSquadBuilder(Alliance* alliance){
    a=alliance;
    squad = new Squad(alliance->getCountryList(), alliance->getName());
}

ConcreteSquadBuilder::~ConcreteSquadBuilder(){
    //client will delete squad
}

void ConcreteSquadBuilder::addGroundUnits(){
    for(auto it=a->getCountryList().begin(); it!=a->getCountryList().end(); it++){
        squad->addSoldiers( (*it) );
        squad->addMedics( (*it) );
        squad->addMechanics( (*it) );
        squad->addTanks( (*it) );
    }
}

void ConcreteSquadBuilder::addAirUnits(){
    cout<<"l\n";
    cout<<a->getCountryList().size()<<endl;
    for(auto it=a->getCountryList().begin(); it!=a->getCountryList().end(); it++){
        cout<<"ll\n";
        squad->addPlanes( (*it) );
    }
}

void ConcreteSquadBuilder::addNavyUnits(){
    for(auto it=a->getCountryList().begin(); it!=a->getCountryList().end(); it++){
        squad->addShips( (*it) );
    }
}

Squad* ConcreteSquadBuilder::getResult(){
    return squad;
}


