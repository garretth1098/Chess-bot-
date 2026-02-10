
#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;
class Piece;

//acts as the model in my MVC architecture. Holds the game state along with all the pieces 
class Board
{
    protected:
       static const int ROWS = 8;
       static const int COLM = 8; 
    
        Piece* CurrBoard[ROWS][COLM]; //each square points to a piece or null pointer  

    public:
        Board();
        virtual ~Board();
        
        void printBoard();
        void loadBoard(string fen); //------------> takes in a FEN string and loads it into the array
};




#endif
