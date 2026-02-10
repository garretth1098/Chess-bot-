#include "knight.h"

Knight::Knight(int color)
{
    this->type = Piece::Knight;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Knight::~Knight()
{
    
}

void Knight::move()
{

}