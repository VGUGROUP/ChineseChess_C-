#include "rule.h"

rule::rule()
{

}

piece rule::findFirstPieceOnRow(std::pair<int, int> currentPosition, state *currentstate)
{
    std::vector<piece> RedPiece = currentstate->getRedPiece();

    while(currentPosition.second >= minRow && currentPosition.second <= maxRow)
    {
        std::find_if(RedPiece.begin(),RedPiece.end(),
        [](piece _piece)->bool
        {
                         if(_piece.)
                    return  true;
        });
    }
}
