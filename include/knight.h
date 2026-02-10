#include "piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H

class Knight : public Piece
{
    
    public: 
        Knight(int color);
        virtual ~Knight();

        void move() override;

};


#endif