#ifndef PLAYER_H
#define PLAYER_H

#define RED 1
#define BLACK -1

#include <vector>
#include <piece.h>
#include <utility>
#include <map>
#include <memory>
#include <iostream>
#include <algorithm>
#include <state.h>
#include <rule.h>
class player : public rule
{
public:
    player();
    void createRedPiece();
    void createBlackPiece();
    void update_boardState();
    void movePiece(std::shared_ptr<piece> &_piece,std::pair<int,int> position);
    void capture(std::pair<int,int> position);

private:
    int currentPlayer = 0; //RED: user , BLACK: minimax , 0: undefined
    std::vector< std::shared_ptr<piece> > RedPiece,BlackPiece;
    // "boardState" list map position of each piece and piece object for ease to use in rule class
    std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState;

};

#endif // PLAYER_H
