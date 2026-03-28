#include "queen.h"

Queen::Queen(Color color)
{
    this->type = Piece::Type::Queen;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Queen::~Queen()
{
    
}

void Queen::move()
{

}