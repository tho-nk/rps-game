# C++ Coding Challenges

This application is tested on Ubuntu 22.04 and requires cmake 3.10+, gcc-11.3

## Installation

build
```
mkdir build && cd build
cmake ..
make
```
run
```
./R_P_S
```

## Code
````
There are 2 kinds of player : HumainPlayer and MachinePlayer

There are 4 kinds of strategy: HumainStrategy, RockStrategy, SemiRandStrategy, RandStrategy

HumainPlayer takes HumainStrategy, which will get a choice from standard input

MachinePlayer can take RockStrategy, SeminRandStrategy or RandStrategy correspond to game level : EASY, MEDIUM or HARD

User will setup their game configuration like:
- game difficulty
- round per game

User can also retry with a new configuration

A game result will be displayed to indicate how many win, draw or loses 
````

## Unitest
This project use googletest as a third-party
```
./runTest
```
