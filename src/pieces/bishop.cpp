#include "bishop.h"

Bishop::Bishop(Color color)
{
    this->type = Piece::Type::Bishop;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Bishop::~Bishop()
{
    
}

void Bishop::move()
{

}