#include "piece.h"

#ifndef PAWN_H
#define PAWN_H

class Pawn : public Piece
{
 
    public: 
        Pawn(int color);
        virtual ~Pawn();

        void move() override;

};


#endif