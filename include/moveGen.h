#ifndef MOVE_GEN
#define MOVE_GEN

#include <vector>
#include "move.h"
#include "board.h"

class MoveGenerator
{
    private:

    public:
        std::vector<Move> generatePseudoLegalMoves(const BoardState& state) const;
        std::vector<Move> generateLegalMoves(Board& board) const;
};

#endif