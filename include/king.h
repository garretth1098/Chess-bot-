#include "piece.h"

#ifndef KING_H
#define KING_H

class King : public Piece
{

    
    public: 
        King(int color);
        virtual ~King();

        void move() override;

};


#endif
