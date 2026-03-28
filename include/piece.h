


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
        
        string getSymbol();
        Type getPieceType() const;
        Color getPieceColor() const;

        virtual void move() = 0;


    protected:
        Type type;
        Color color; 
        string unicodeImage;
};   



#endif
