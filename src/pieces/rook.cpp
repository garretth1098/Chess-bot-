#include "rook.h"

Rook::Rook(Color color)
{
    this->type = Piece::Type::Rook;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Rook::~Rook()
{
    
}

void Rook::move()
{

}