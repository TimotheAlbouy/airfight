# Airfight, by Timothé Albouy and Youssef El Hor

Qt game realized during advanced OOP course of the ENSIBS.

## Requirements

This project requires Qt >=5 as well as the `core`, `gui` and `multimedia` modules. It also requires a C++ >= 11 compiler.

To get the full experience, it is preferable to play Airfight on a screen able to display a 1000 pixels by 1000 pixels window. If your screen is to small, you can change the size of the window by editing the `WIDTH` and `HEIGHT` constant attributes of the `Game` class in `game.h`.

## Build

The following steps have been tested on Ubuntu in bash.

To build the project, first go to the directory containing the `airfight` folder, then execute these command lines:
- `mkdir build`
- `cd build`
- `qmake ../airfight/airfight.pro`
- `make`

You will get an executable `airfight` file that launches the game.

Alternatively, you can use Qt Creator to compile the project.

## Playing the game

Just execute the file using `./airfight`.

As said earlier, you can also simply use Qt Creator to play Airfight.