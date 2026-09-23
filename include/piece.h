


#ifndef PIECE_H
#define PIECE_H

#include <string>
using std::string;


class Piece 
{

    // enums need to be declared before member varibles 
    public:
        Piece();
        virtual ~Piece();

        enum class Type {King,Pawn,Knight,Bishop,Rook,Queen};
        enum class Color {White,Black};
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
        
        string getSymbol();
        Type getPieceType() const;
        Color getPieceColor() const;
        int getPieceIndex() const;
        virtual void move() = 0;
        


    protected:
        Type type;
        Color color; 
        string unicodeImage;
};   



#endif
