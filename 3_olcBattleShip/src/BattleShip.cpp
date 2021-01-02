//
// Created by bebti on 1/13/2017.
//

#include "BattleShip.h"
BattleShip::BattleShip()
{
    int dim = 0;
    int numBoats = 0;
    std::cout << "Please enter dimensions of board: ";

    std::cin >> dim;

    b = new Board(dim);
    sinkModeOn = false;
    turnNumber = 0;

    std::cout << "Please enter the number of boats of each size:" << std::endl << std::endl;

    for(int i = 1; i <= 5; i++ )
    {
        std::cout << "Please enter number of boats with size: " << i << std::endl;
        std::cin >> numBoats;
        this->boats.push_back(std::pair<int,int> (i,numBoats));

    }




    this->runGame();
}

BoxResult BattleShip::selectBox()
{
    BoxResult r;

    int x = 0;
    int y = 0;

    bool correctCoordInput = false;
    bool correctResultInput = false;
    while(!correctCoordInput)
    {
        std::cout << "Please enter box coordinates: X Y" << std::endl;
        std::cin >> x >> y;
        std::cout << std::endl;
        if( x <= b->size()-1 && x >= 0)
        {
            if( y <= b->size()-1 && y >= 0)
            {
                correctCoordInput = true;
            }
        }
        else
        {
            correctCoordInput = false;
            std::cout << "Please enter coordinates within the size range." << std::endl;
            std::cout << "Choose from values: 0-" << b->size()-1 <<std::endl;
        }

    }


    while(!correctResultInput)
    {
        std::string result = "";
        std::cout << "Was it a hit or miss? ( Type hit or miss )" << std::endl;
        std::cin >> result;
        std::cout << std::endl;

        if(result == "miss" || result == "hit")
        {
            correctResultInput= true;
        }
        else
        {
            correctResultInput = false;
            std::cout << "Please enter only: \"hit\" for hit, \"miss\" for miss." << std::endl;
        }

        r.result = result;
    }

    r.x = x;
    r.y = y;

    return(r);
}

void BattleShip::updateBoard(BoxResult r)
{
    if(r.result == "hit")
    {
        b->setHit(r.x,r.y);
        sinkModeOn = true;
        hitModeBox = r;
    } else
    {
        b->setMiss(r.x,r.y);
    }
}

void BattleShip::runGame()
{
    BoxResult r;
    displayBoard();
    while(!isTerminated())
    {
        r = selectBox();
        updateBoard(r);
        displayBoard();
        sinkQuery(r);
        calculateBestChoice();
        displayBoard();
    }
}

void BattleShip::calculateBestChoice()
{
    if(sinkModeOn)
    {
        std::cout << this->pc->calculateSinkScore(sinkModeOn,this->b,hitModeBox,boats);

    }
    else
    {
        turnNumber++;
        displayBoard();
        pc->traverseBoard(b,boats);
        //exitQuery();
    }
}

void BattleShip::sinkQuery(BoxResult r)
{
    bool input = false;

    std::string in = "";
    int boatIn = 0;
    while(!input && r.isHit())
    {

        std::cout << " Was ship sunk? (Y/N)" << std::endl;
        std::cin >> in;
        if(in == "n" || in == "N")
        {
            input = true;
            sinkModeOn = true;
        }
        else if(in == "y" || in == "Y")
        {
            in = "";
            input = true;
            sinkModeOn = false;
            std::cout << "Enter the size of the ship: " << std::endl;
            std::cin >> boatIn;

            for(std::pair<int,int> &b : boats)
            {
                if(b.first == boatIn)
                {
                    b.second--;
                    if(b.second <= 0)
                    {
                        b.second = 0;
                    }
                }
            }


        }
        else{
            input = false;
            std::cout << "Incorrect input. Try again." << std::endl;
        }

        std::cout << std::endl;
    }

}
void BattleShip::exitQuery()
{
    std::string input;
    std::cout << "Go to Next round? (Y/N)" << std::endl;
    std::cin >> input;

    if(input != "Y" || input != "y")
    {
        terminate = false;
    } else
    {
        terminate = true;
    }
}
