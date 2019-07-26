#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H
#include <memory>
#include <piece.h>
#include <utility>
#include <map>
#include <iostream>

class board_view
{
public:
    board_view( std::map<std::pair<int,int>, std::shared_ptr<piece>> &_boardState);
    void draw_board();


private:
     std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState;
};

#endif // BOARD_VIEW_H
