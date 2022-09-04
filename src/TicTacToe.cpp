//
// Created by MrMer on 04-09-2022.
//
#include <iostream>
#include <string>

using namespace std::string_literals;
class Square
{
private:
    bool user;
    bool occupied;

public:
    Square()
    {
        occupied = false;
    }

    void fill(bool user)
    {
        if (occupied)
        {
            throw "Square already occupied!"s;
        }
        else
        {
            this->user = user;
            occupied = true;
        }
    }

    const bool isOccupied()
    {
        return occupied;
    }

    const bool getUser()
    {
        return user;
    }
};

class Board
{
private:
    Square squares[9];

public:
    void getSquareNo(bool user)
    {
        int squareNo;
        std::cout << "Enter the square number to fill:";
        std::cin >> squareNo;
        if (squareNo < 1 || squareNo > 9)
        {
            throw "Invalid square number!";
        }
        else
        {
            squares[squareNo - 1].fill(user);
        }
    }

    void printSquare()
    {
        for (int i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
            {
                std::cout << std::endl;
            }
            if (squares[i].isOccupied())
            {
                if (squares[i].getUser())
                {
                    std::cout << "X" << " ";
                }
                else
                {
                    std::cout << "O" << " ";
                }
            }
            else
            {
                std::cout << "_" << " ";
            }
        }
        std::cout << std::endl;
    }

    void playGame()
    {
        bool user = true;
        for (int i = 0; i < 9; i++)
        {
            printSquare();
            input:
            try {

                getSquareNo(user);
            }
            catch (std::string e)
            {
                std::cout << e << std::endl;
                goto input;
            }
            if (checkWin(user))
            {
                printSquare();
                std::cout << "Player " << (user ? "1" : "2") << " wins!" << std::endl;
                return;
            }
            user = !user;
        }
        std::cout << "Draw!" << std::endl;
    }


    bool checkWin(bool user)
    {
        int win[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
        for (int i = 0; i < 8; i++)
        {
            if (squares[win[i][0]].isOccupied() && squares[win[i][1]].isOccupied() && squares[win[i][2]].isOccupied())
            {
                if (squares[win[i][0]].getUser() == user && squares[win[i][1]].getUser() == user && squares[win[i][2]].getUser() == user)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Board board;
    board.playGame();
}