#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece
{
    public:
        virtual void computeAvailableMovements(std::vector<Piece*>, std::vector<Piece*>); // NON OPTIMAL
};

#endif // KING_H