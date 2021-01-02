//
// Created by bebti on 1/18/2017.
//

#ifndef BATTLESHIP_PROJ_PROBABILITYCALCULATOR_H
#define BATTLESHIP_PROJ_PROBABILITYCALCULATOR_H


#include <algorithm>
#include <sstream>
#include "Board.h"
#include "BattleShip.h"
#include "BoxHighestScore.h"
#include "BoxResult.h"


// Structure stores information about current box.
// Contains information about how far adjacent boxes extend outward without being a hit or miss.
struct LineSearch
{
    LineSearch(std::string d, int i, int j) : direction{d}, searchable{true}, score{0}
    {
        this->i = i;
        this->j = j;
    }

    void calcScore(bool sinkMode, Board *b, int ii, int jj )
    {
        int iii = i+ii;
        int jjj = j+jj;

        if(!b->isOutOfBounds(iii,jjj)) {
            State s = b->getStateMatrix()[i + ii][j + jj];


            if (s == miss || ((s == hit)) && !sinkMode) {
                searchable = false;
            }

            if (searchable)
            {
                if(sinkMode == true)
                {
                    score += 100;
                } else {
                    score++;
                }

                if(s == miss)
                {
                    score = 0;
                }
            }
        }
    }


    std::string direction;
    bool searchable;
    int score;
    int i;
    int j;
};

class BattleShip;
class ProbabilityCalculator
{
public:
    ProbabilityCalculator();



    static BoxHighestScore calculateLengths(Board *b, int i, int j,  std::vector<std::pair<int,int>> boats)
    {
        BoxHighestScore boxHighestScore(i, j);


        std::vector<LineSearch> m;

        LineSearch n("n",i ,j);
        LineSearch s("s",i ,j);
        LineSearch e("e",i ,j);
        LineSearch w("w",i ,j);
        int ii = 0;

        for(int ii = 0; ii < b->size(); ii++)
        {
            n.calcScore(false,b,-ii,0);
            s.calcScore(false,b,+ii,0);
            e.calcScore(false,b,0,+ii);
            w.calcScore(false,b,0,-ii);

        }


        m.push_back(n);
        m.push_back(s);
        m.push_back(e);
        m.push_back(w);

        for(int i = 0; i < m.size();i++)
        {
            for(std::pair<int,int> z : boats)
            {
                if(z.second > 0) {
                    if (m.at(i).score >= z.first) {
                        boxHighestScore.score += z.first;
                    }
                }
            }
        }

        return(boxHighestScore);
    }
    static std::string calculateSinkScore(bool sinkMode,Board *b, BoxResult r,  std::vector<std::pair<int,int>> boats)
    {

        int i = r.x;
        int j = r.y;
        std::vector<LineSearch> m;

        LineSearch n("n",i ,j);
        LineSearch s("s",i ,j);
        LineSearch e("e",i ,j);
        LineSearch w("w",i ,j);
        int ii = 0;

        for(int ii = 1; ii < 4; ii++)
        {
            n.calcScore(sinkMode,b,-ii,0);
            s.calcScore(sinkMode,b,+ii,0);
            e.calcScore(sinkMode,b,0,+ii);
            w.calcScore(sinkMode,b,0,-ii);

        }

        m.push_back(n);
        m.push_back(s);
        m.push_back(e);
        m.push_back(w);

        std::sort(m.begin(),m.end(), [](LineSearch l1, LineSearch l2)
        {
           if(l1.score > l2.score)
           {
               return(true);
           }
           else{
               return(false);
           }
        });

        std::string out = "Choose: " + m.front().direction + "\n\n";
        return(out);

    }


    static void traverseBoard(Board *b, std::vector<std::pair<int,int>> boats)
    {
        std::vector<BoxHighestScore> vec;
        int sz = b->size();

        // Calculate the score of each box
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < sz; j++)
            {
                BoxHighestScore temp = calculateLengths(b,i,j,boats);

                vec.push_back(temp);
            }
        }

        // Sort the boxes from highest to lowest scores
        std::sort(vec.begin(),vec.end(),[](BoxHighestScore b1, BoxHighestScore b2)
        {
            if(b1.score > b2.score)
            {
                return(true);
            }
            else if(b2.score > b1.score)
            {
                return(false);
            }
            else if(b1.score == b2.score)
            {
                if(b1.isEven)
                {
                    return(true);
                } else
                {
                    return(false);
                }
            }
        });

        // Store all of the highest scoring boxes with the same value in a different vector.
        std::vector<BoxHighestScore> highestScores;
        for(BoxHighestScore score : vec)
        {
            int highestScore = vec[0].score;

            if(score.score >= highestScore)
            {
                highestScores.push_back(score);
            }
        }

        // Shuffle the boxes with highest scores.
        std::random_shuffle(highestScores.begin(),highestScores.end());

        // Choose the first element to fire.
        std::cout << highestScores[0] <<  std::endl;
    }

    static int calculateSingleDirection(int i, int j, Board *b)
    {
        int score = 0;

        if(!b->isOutOfBounds(i,j))
        {
            if (b->printBoxStatus(i,j) == "?")
            {
                score++;
            }
        }
        return(score);
    }
    static int calculateDirections(int i, int j, Board *b)
    {
        int sum = 1;
        for(int ii = 1; ii < b->size(); ii++)
        {
            sum += calculateSingleDirection(i-ii, j, b);
            sum += calculateSingleDirection(i+ii, j, b);
            sum += calculateSingleDirection(i, j+ii, b);
            sum += calculateSingleDirection(i, j-ii, b);
        }

        return(sum);
    }


    static void showPointMap(int size, std::vector<BoxHighestScore> vec)
    {
        std::cout << std::endl;
        std::cout << "Printing point map." << std::endl;
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                std::cout << (vec[i * size + j]).score << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};


#endif //BATTLESHIP_PROJ_PROBABILITYCALCULATOR_H
