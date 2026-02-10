#include "piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece
{    
    public: 
        Rook(int color);
        virtual ~Rook();

        void move() override;

};


#endif