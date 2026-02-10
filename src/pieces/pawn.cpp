#include "pawn.h"

Pawn::Pawn(int color)
{
    this->type = Piece::Pawn;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Pawn::~Pawn()
{
    
}

void Pawn::move()
{

}