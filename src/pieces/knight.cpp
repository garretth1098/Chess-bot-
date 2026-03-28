#include "knight.h"

Knight::Knight(Color color)
{
    this->type = Piece::Type::Knight;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Knight::~Knight()
{
    
}

void Knight::move()
{

}