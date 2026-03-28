#include "piece.h"

#ifndef ROOK_H
#define ROOK_H

class Rook : public Piece
{    
    public: 
        Rook(Color color);
        virtual ~Rook();

        void move() override;

};


#endif