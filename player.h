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
class player
{
public:
    player();
    void createRedPiece();
    void createBlackPiece();


private:
    int team = 0;
    std::vector< std::unique_ptr<piece> > RedPiece,BlackPiece;
    // "boardState" list map position of each piece and piece object for ease to use in rule class
    std::map<std::pair<int,int>,piece> boardState;

};

#endif // PLAYER_H
