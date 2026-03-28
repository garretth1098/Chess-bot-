#include "piece.h"

#ifndef BISHOP_H
#define BISHOP_H

class Bishop : public Piece
{
    
    public: 
        Bishop(Color color);
        virtual ~Bishop();

        void move() override;
};


#endif