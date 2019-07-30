#ifndef STATE_H
#define STATE_H
#include "player.h"
#include <memory>
#include <utility>
#include <board_view.h>
#define RED 1
#define BLACK -1


class state : public board_view
{
public:
    struct AB_result{
        AB_result(){}
        AB_result(int score,std::shared_ptr<piece> &piece,std::pair<int,int> &point){
                this->_score = score;
                this->_piece = piece;
                this->_toPoint = point;
        }

          int _score = 0;
          std::shared_ptr<piece> _piece = nullptr;
          std::pair<int,int> _toPoint = {0,0};
    };
    state();
    state(state &_state);
    void setNextMove_AB();
    int getStateScore();
    bool isEndGame();
    void initGameState();
    void switchPlayer();
    void nextMove();
    std::shared_ptr<state> nextState(std::shared_ptr<piece> &_piece, std::pair<int,int> position);
    std::shared_ptr<player> getPlayer() const;
    void setPlayer(const std::shared_ptr<player> &player1);
    AB_result alphabeta(state &state,int depth,bool isMax,int alpha, int beta);
    std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > > getAllposibleMoves();
    void draw_state(state &_state);
    bool movePiece(std::shared_ptr<piece> &_piece,std::pair<int,int> position);

    void inputMove();
private:
    std::shared_ptr<player> _player;
};

#endif // STATE_H
