#include "bishop.h"

Bishop::Bishop(int color)
{
    this->type = Piece::Bishop;
    this->color = color;

    unicodeImage = this->getSymbol();
}


Bishop::~Bishop()
{
    
}

void Bishop::move()
{

}