#include "piece.h"

#ifndef QUEEN_H
#define QUEEN_H

class Queen : public Piece
{
    
    public: 
        Queen(Color color);
        virtual ~Queen();

        void move() override;

};


#endif