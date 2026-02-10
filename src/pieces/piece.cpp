#include "piece.h"


Piece::Piece()
{
    unicodeImage = this->getSymbol();
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

void Piece::move()
{
    
}