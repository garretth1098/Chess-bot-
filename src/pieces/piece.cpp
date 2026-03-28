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
        case King:
            return (color == White) ? "♚" : "♔";
        case Queen:
            return (color == White) ? "♛" : "♕";
        case Rook:
            return (color == White) ? "♜" : "♖";
        case Bishop:
            return (color == White) ? "♝" : "♗";
        case Knight:
            return (color == White) ? "♞" : "♘";
        case Pawn:
            return (color == White) ? "♟" : "♙";
        default:
            return " ";      // empty square
    }
}

void Piece::move()  // Double check inheritance and abstract methods 
{
    
}