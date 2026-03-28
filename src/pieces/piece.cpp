#include "piece.h"


Piece::Piece()
{
    unicodeImage = this->getSymbol();  // useless because I never call it TODO remove perhaps 
}

Piece::~Piece()
{

}

string Piece::getSymbol() 
{
    switch(type) {
        case Type::King:
            return (color == Color::White) ? "♚" : "♔";
        case Type::Queen:
            return (color == Color::White) ? "♛" : "♕";
        case Type::Rook:
            return (color == Color::White) ? "♜" : "♖";
        case Type::Bishop:
            return (color == Color::White) ? "♝" : "♗";
        case Type::Knight:
            return (color == Color::White) ? "♞" : "♘";
        case Type::Pawn:
            return (color == Color::White) ? "♟" : "♙";
        default:
            return " ";      // empty square
    }
}


Piece::Type Piece::getPieceType() const
{
    return this->type;
}

Piece::Color Piece::getPieceColor() const
{
    return this->color;
}

void Piece::move()  // Double check inheritance and abstract methods 
{
    
}