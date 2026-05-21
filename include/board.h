
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
    Bitboard bitboards[12];

    // castling rights
    bool WKS, WQS, BKS, BQS;

    //en passant targets 
    Bitboard passantTarget;

    std::uint8_t turn;
};

struct Move; //forward declaration

//acts as the model in my MVC architecture. Holds the game state along with all the pieces 
class Board
{
    protected:
       static const int ROWS = 8;
       static const int COLM = 8; 
    
        Piece* CurrBoard[ROWS][COLM]; //----------> each square points to a piece or null pointer  

    public:
        Board();
        virtual ~Board();
        
        void printBoard();
        void loadBoard(string fen); //------------> takes in a FEN string and loads it into the array
        const Piece* getPiece(int row, int colm) const;
        Piece* getPiece(int row, int colm);
        void movePiece(int startRow, int startCol, int endRow, int endCol);
        bool isLegalMove(Move& move);
};




#endif
