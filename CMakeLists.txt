cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Battleship)
project (${Battleship} VERSION 1.0)


add_library
(
Action.cpp
Action.h
BattleShip.cpp
BattleShip.h
Coordinates.cpp
Coordinates.h
Grid.cpp
Grid.h
GridCell.cpp
Gridcell.h
NavalUnit.cpp
NavalUnit.h
Player.cpp
Player.h
Submarine.cpp
Submarine.h
SupportVessel.cpp
SupportVessel.h
)

add_executable(main.cpp)