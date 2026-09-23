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

int Piece::getPieceIndex() const
{
    if (color == Color::White)
    {
        switch (type)
        {
            case Type::Pawn:   return WHITE_PAWN;
            case Type::Knight: return WHITE_KNIGHT;
            case Type::Bishop: return WHITE_BISHOP;
            case Type::Rook:   return WHITE_ROOK;
            case Type::Queen:  return WHITE_QUEEN;
            case Type::King:   return WHITE_KING;
        }
    }
    else
    {
        switch (type)
        {
            case Type::Pawn:   return BLACK_PAWN;
            case Type::Knight: return BLACK_KNIGHT;
            case Type::Bishop: return BLACK_BISHOP;
            case Type::Rook:   return BLACK_ROOK;
            case Type::Queen:  return BLACK_QUEEN;
            case Type::King:   return BLACK_KING;
        }
    }

    return EMPTY;
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