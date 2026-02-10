#include "rook.h"

Rook::Rook(int color)
{
    this->type = Piece::Rook;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Rook::~Rook()
{
    
}

void Rook::move()
{

}