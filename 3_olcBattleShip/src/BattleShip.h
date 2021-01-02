//
// Created by bebti on 1/13/2017.
//

#ifndef BATTLESHIP_PROJ_BATTLESHIP_H
#define BATTLESHIP_PROJ_BATTLESHIP_H

#include <iostream>
#include <vector>
#include "Board.h"
#include "ProbabilityCalculator.h"
#include "BoxResult.h"

/*
 * Alberto Heras
 * Jan 13,2017
 *
 * Battleship:
 */

class ProbabilityCalculator;


class BattleShip
{
public:

    BattleShip();
    ~BattleShip() {delete(b);}

    BattleShip(int sz)
    {
        b = new Board(sz);
        terminate = false;
        sinkModeOn = false;
        turnNumber = 0;

        this->runGame();
    }

    void displayBoard() { std::cout << "Turn Number: " << turnNumber << std::endl << std::endl << *b << std::endl; }

    BoxResult selectBox();
    void runGame();
    bool isTerminated() {return(terminate);}
    void updateBoard(BoxResult r);
    void exitQuery();
protected:
    Board* b;
private:
    int turnNumber;
    BoxResult hitModeBox;
    bool sinkModeOn;
    ProbabilityCalculator *pc;
    bool terminate;
    std::vector<std::pair<int,int>> boats;

    void calculateBestChoice();

    void sinkQuery(BoxResult r);
};


#endif //BATTLESHIP_PROJ_BATTLESHIP_H
