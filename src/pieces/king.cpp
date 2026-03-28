#include "king.h"

King::King(Color color)
{
    this->type = Piece::Type::King;
    this->color = color;

    unicodeImage = this->getSymbol();
}

King::~King()
{   }

void King::move()
{
    
}