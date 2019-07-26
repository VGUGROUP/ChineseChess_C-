#ifndef STATE_H
#define STATE_H
#include "player.h"
#include <memory>
#define RED 1
#define BLACK -1

class state
{
public:
    state();
    bool isEndGame();
    void initGameState();
    void switchPlayer();

private:
    std::unique_ptr<player> _player;
};

#endif // STATE_H
