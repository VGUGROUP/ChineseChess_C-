
#ifndef RULE_H
#define RULE_H
#include <vector>
#include <algorithm>

#include "piece.h"
#include "state.h"

class rule
{
public:
    rule();
    piece findFirstPieceOnRow(std::pair<int,int> currentPosition, state *currentstate);
private:
    int maxRow = 10, minRow = 1, maxCol = 9 , minCol = 1;
};

#endif // RULE_H
