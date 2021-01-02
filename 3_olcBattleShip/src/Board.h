//
// Created by bebti on 1/12/2017.
//

#ifndef BATTLESHIP_PROJ_BOARD_H
#define BATTLESHIP_PROJ_BOARD_H

#include <iostream>
#include <string>
#include <map>

enum State { unknown,hit, miss};

class Board
{
private:
    State **board;
    int sz;
    std::map<State, std::string> m;

public:

    Board(int s): sz{s},  board{new State*[s]}, m{{unknown,"?"},{hit,"X"},{miss,"O"}}
    {


        for(int i = 0; i < sz; i++)
        {
            board[i] = new State[sz];

            for(int j = 0; j < sz; j++)
            {
                setUnknown(i,j);
            }
        }
    }

    bool isOutOfBounds(int i, int j)
    {
        if(i > sz-1 || i < 0)
        {
            return(true);
        }
        else
        {
            if(j > sz-1 || j < 0)
            {
                return(true);
            }
            else
            {
                return(false);
            }
        }
    }

    int size() { return(this->sz); }
    std::string printBoxStatus(int i, int j) const
    {
        if(i < 0 || j < 0)
        {
            return(m.at(miss));
        }
        else if(i >= sz || j >= sz)
        {
            return(m.at(miss));
        }
        else
        {
            State s = board[i][j];

            return (m.at(s));
        }
    }

    const State& operator()(int i, int j) const
    {
        return(board[i][j]);
    }

    friend std::ostream& operator<<(std::ostream& out, const Board& b)
    {
        out << " ";
        for(int i = 0; i < b.sz; i++)
        {
            out << " " << i;
        }

        out << std::endl;
        for(int i = 0; i < b.sz; i++)
        {
            out << i << " ";

            for(int j = 0; j < b.sz; j++)
            {
                out << b.printBoxStatus(i,j) << " ";
            }

            out << std::endl;
        }

        return(out);
    }



    void setUnknown(int i, int j)    { board[i][j] = unknown;    }
    void setHit(int i, int j)       { board[i][j] = hit;        }
    void setMiss(int i, int j)      { board[i][j] = miss;       }
    State** getStateMatrix() {return(this->board);}
};




#endif //BATTLESHIP_PROJ_BOARD_H
