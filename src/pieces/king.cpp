#include "king.h"

King::King(int color)
{
    this->type = Piece::King;
    this->color = color;

    unicodeImage = this->getSymbol();
}

King::~King()
{   }

void King::move()
{
    
}