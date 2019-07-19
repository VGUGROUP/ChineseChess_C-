#ifndef STATE_H
#define STATE_H
#include "piece.h"
#include<vector>
class state
{
public:
    state();
    std::vector<piece> getBlackPiece() const;
    std::vector<piece> getRedPiece() const;

private:
    std::vector<piece> RedPiece,BlackPiece;
};

#endif // STATE_H
