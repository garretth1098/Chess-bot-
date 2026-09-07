
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cstdint>

using namespace std;
using Bitboard = uint64_t;
class Piece;



struct BoardState
{
    // bitboards for each of the piece types 
    Bitboard bitboards[12]{};

    // castling rights
    bool WKS, WQS, BKS, BQS = true;

    //en passant targets 
    Bitboard passantTarget = 0;

    std::uint8_t turn = 0;  // 0 = white, 1 = black
};

struct Move; //forward declaration

//acts as the model in my MVC architecture. Holds the game state along with all the pieces 
class Board
{
    protected:
       static const int ROWS = 8;
       static const int COLM = 8; 
    
        Piece* CurrBoard[ROWS][COLM]; //----------> each square points to a piece or null pointer 
        
        // stack used to hold moves in succession 
        static const int MAX_MEM = 1024;  
        BoardState* stateStack;
        int stackIndex = 0;

    public:
        Board();
        virtual ~Board();
        
        void printBoard();
        void loadBoard(string fen); //-------------------> takes in a FEN string and loads it into the array
        void updateBoard();//----------------------------> current state
        void updateBoard(const BoardState& otherState); // specified state
        // I could simply rely on bitboard tracking but chose a hybrid design 
        // becasuse I dont want to refactor how my view draws everything

        const Piece* getPiece(int row, int colm) const;
        Piece* getPiece(int row, int colm);
        void movePiece(int startRow, int startCol, int endRow, int endCol);
        void undo();
        bool isLegalMove(Move& move);
};




#endif
