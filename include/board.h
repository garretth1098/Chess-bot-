
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
        
        // stack used to hold moves in succession 
        static const int MAX_MEM = 1024;  //probably enough lmao
        BoardState* stateStack;
        int stackIndex = 0;

        enum PieceIndex
        { 
            WHITE_PAWN,    // = 0
            WHITE_KNIGHT,  // = 1
            WHITE_BISHOP,  // = 2
            WHITE_ROOK,    // = 3
            WHITE_QUEEN,   // = 4
            WHITE_KING,    // = 5
            BLACK_PAWN,    // = 6
            BLACK_KNIGHT,  // = 7
            BLACK_BISHOP,  // = 8
            BLACK_ROOK,    // = 9 
            BLACK_QUEEN,   // = 10
            BLACK_KING,    // = 11
            EMPTY,         // = 12

            WHITE,         // = 13
            BLACK,         // = 14
        };

        
        enum enumSquare {  // a1 = 0; h8 = 63
            a1, b1, c1, d1, e1, f1, g1, h1,
            a2, b2, c2, d2, e2, f2, g2, h2,
            a3, b3, c3, d3, e3, f3, g3, h3,
            a4, b4, c4, d4, e4, f4, g4, h4,
            a5, b5, c5, d5, e5, f5, g5, h5,
            a6, b6, c6, d6, e6, f6, g6, h6,
            a7, b7, c7, d7, e7, f7, g7, h7,
            a8, b8, c8, d8, e8, f8, g8, h8
        };

    public:
        Board();
        virtual ~Board();
        
        void printBoard();
        void loadBoard(string fen); //--------------> takes in a FEN string and loads it into the array
        void updateBoard(const BoardState& state); // takes in a specified state reloads Piece array
        // I could simply rely on bitboard tracking but chose a hybrid design 
        // becasuse I dont want to refactor how my view draws everything

        const Piece* getPiece(int row, int colm) const; //used for GUI drawing 
        Piece* getPiece(int row, int colm);

        Piece* createPiece(int pieceType); // //helper functions for update board
        int getPiece(const BoardState& state, int square);

        //two move functions one for the GUI using an array and one for the engine using bitboards
        void movePiece(const Move& move);
        void movePiece(int startRow, int startCol, int endRow, int endCol);
        
        void undo(); //---------------> reverses previous move by loading last boardstate
        bool isLegalMove(Move& move); 
};




#endif
