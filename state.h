#ifndef STATE_H
#define STATE_H
#include "player.h"
#include <memory>
#include <board_view.h>
#define RED 1
#define BLACK -1

class state : public board_view
{
public:
    state();
    state(state &_state);
    bool isEndGame();
    void initGameState();
    void switchPlayer();
    void nextMove();
    std::shared_ptr<state> nextState(std::shared_ptr<piece> &_piece, std::pair<int,int> position);
    std::shared_ptr<player> getPlayer() const;
    void setPlayer(const std::shared_ptr<player> &player1);
    void alphabeta();
    std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > > getAllposibleMoves();
    void draw_state(state &_state);
    void movePiece(std::shared_ptr<piece> &_piece,std::pair<int,int> position);
private:
    std::shared_ptr<player> _player;
};

#endif // STATE_H
