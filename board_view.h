#ifndef BOARD_VIEW_H
#define BOARD_VIEW_H
#include <memory>
#include <piece.h>
#include <utility>
#include <map>
#include <iostream>
#include <player.h>

class board_view
{
public:
    board_view();
    static void draw_board(const std::shared_ptr<player> &_player);
    static void draw_river();


private:

};

#endif // BOARD_VIEW_H
