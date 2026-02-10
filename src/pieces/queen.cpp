#include "queen.h"

Queen::Queen(int color)
{
    this->type = Piece::Queen;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Queen::~Queen()
{
    
}

void Queen::move()
{

}