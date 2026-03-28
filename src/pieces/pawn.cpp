#include "pawn.h"

Pawn::Pawn(Color color)
{
    this->type = Piece::Type::Pawn;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Pawn::~Pawn()
{
    
}

void Pawn::move()
{

}