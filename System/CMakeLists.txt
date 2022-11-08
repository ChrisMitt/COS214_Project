cmake_minimum_required(VERSION 3.23)
project(COS214_Project)

set(CMAKE_CXX_STANDARD 11)

set(Headers Person.h Vehicle.h UnitFactory.h VehicleFactory.h Status.h UnitBackup.h SoldierState.h Decorator.h ResourceManagement.h CountryObserver.h Country.h Alliance.h Phase.h PhasesofWar.h PersonFactory.h WarTheatre.h Squad.h DeployType.h DeployContext.h)

add_executable(COS214_Project Vehicle.cpp Person.cpp UnitFactory.cpp VehicleFactory.cpp Status.cpp UnitBackup.cpp SoldierState.cpp Decorator.cpp ResourceManagement.cpp CountryObserver.cpp Country.cpp Alliance.cpp WarEngine.cpp PhasesofWar.cpp Phase.cpp PersonFactory.cpp WarTheatre.cpp Squad.cpp DeployType.cpp DeployContext.cpp)