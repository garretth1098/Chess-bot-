


#ifndef PIECE_H
#define PIECE_H

#include <string>
using std::string;


class Piece 
{
    protected:
        static const int None = 0;                 //binary representation:
        static const int King = 1;                 // 10    110 
        static const int Pawn = 2;                 // color type 
        static const int Knight = 3;
        static const int Bishop = 4;
        static const int Rook = 5;
        static const int Queen = 6;

        static const int White = 8;
        static const int Black = 16;

        int type;
        int color; 
        string unicodeImage;


    public:
        Piece();
        virtual ~Piece();
        
        string getSymbol();
        
        virtual void move() = 0;

        friend class Board;    // piece values needed for color in loadBoard()
       

};   



#endif
