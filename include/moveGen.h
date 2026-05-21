#ifndef 
#define MOVE_GEN

#include <vector>

class MoveGenerator
{
    private:

    public:
        std::vector<Move> generatePseudoLegalMoves(const BoardState& state) const;
        std::vector<Move> generateLegalMoves(Board& board) const;
};

#endif