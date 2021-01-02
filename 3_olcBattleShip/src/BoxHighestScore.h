//
// Created by bebti on 1/19/2017.
//

#ifndef BATTLESHIP_PROJ_BOXHIGHESTSCORE_H
#define BATTLESHIP_PROJ_BOXHIGHESTSCORE_H

#include <ostream>

struct BoxHighestScore
{
    BoxHighestScore(): x{0}, y{0}, score{0}, isEven{true} {}
    BoxHighestScore(int i, int j)
    {
        x = i;
        y = j;
        score = 0;
        if( ((x + y) % 2) == 0)
        {
            isEven = true;
        } else
        {
            isEven = false;
        }

    }
    BoxHighestScore operator=(const BoxHighestScore& rhs)
    {
        this->x = rhs.x;
        this->y = rhs.y;
        this->score = rhs.score;
        this->isEven = rhs.isEven;

        return(*this);
    }

public:
    friend std::ostream& operator<<(std::ostream& os, const BoxHighestScore& box)
    {
        os << "Best choice is: " << box.x << " " << box.y << std::endl
           << "Score: " << box.score << std::endl;

        return(os);
    }
    int x;
    int y;
    int score;
    bool isEven;
};

#endif //BATTLESHIP_PROJ_BOXHIGHESTSCORE_H
