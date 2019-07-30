#include "state.h"

state::state()
{

}

state::state(state &_state)
{
    this->_player = std::shared_ptr<player> (new player(*_state.getPlayer()));
}

void state::setNextMove_AB()
{
    auto result = alphabeta(*this,1,false,-9999,9999);
    movePiece(result._piece,result._toPoint);
    draw_state(*this);
}

int state::getStateScore()
{
    return _player->getValueOfState();
}

bool state::isEndGame()
{
    auto currentPlayer = _player->getCurrentPlayer();
    bool result = _player->isKingExist(currentPlayer);
    return  !result;
}

void state::initGameState()
{
    _player = std::shared_ptr<player> (new player);
    _player->setCurrentPlayer(RED);
    draw_state(*this);
    inputMove();

}

void state::switchPlayer()
{
    if(_player->getCurrentPlayer() == RED){
      _player->setCurrentPlayer(BLACK);
    }
    else if (_player->getCurrentPlayer() == BLACK) {
        _player->setCurrentPlayer(RED);
    }
}

std::shared_ptr<state> state::nextState(std::shared_ptr<piece> &_piece, std::pair<int, int> position)
{
    std::shared_ptr<state> _nextState(new state(*this));
    auto nextstate_piece = _nextState->getPlayer()->getSimilarPiece(_piece);
    _nextState->movePiece(nextstate_piece,position);
    return  _nextState;

}

std::shared_ptr<player> state::getPlayer() const
{
    return _player;
}

void state::setPlayer(const std::shared_ptr<player> &_player)
{
    this->_player = _player;
}

std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > > state::getAllposibleMoves()
{
    return _player->computelegalMoves();
}

void state::draw_state(state &_state)
{
    board_view::draw_board(_state.getPlayer());
}

bool state::movePiece(std::shared_ptr<piece> &_piece, std::pair<int, int> position)
{
    bool result = this->_player->movePiece(_piece,position);
    return  result;
}

void state::inputMove()
{
    std::string symbol,row,col;
    std::pair<int,int> position;
    std::cout <<"input piece symbol:";
    std::getline(std::cin,symbol);
    std::cout<<"input position: "<<std::endl;
    std::cout<<"Row: ";
    std::getline(std::cin,row);
    std::cout<<"Col: ";
    std::getline(std::cin,col);

    position = {std::stoi(row),std::stoi(col)};
    auto piece = _player->getPiecBySymbol(symbol);
    if(piece == nullptr){
        std::cout<<"invalid name"<<std::endl;
    }
    if(!movePiece(piece,position)){
        std::cout<<"invalid position"<<std::endl;
    };
    setNextMove_AB();

}

state::AB_result state::alphabeta(state &_state, int depth, bool isMax, int alpha, int beta)
{
    if(_state.isEndGame()){
        AB_result temp;
        temp._score = (9999999)*_state.getPlayer()->getCurrentPlayer();
        return temp;
    }

    if(depth == 0){
        AB_result temp;
        temp._score = _state.getStateScore();
        return  temp;
    }

    _state.switchPlayer();
    auto moves = _state.getAllposibleMoves();
    std::vector<AB_result> eval_result;

    for (unsigned int i =0 ;i <moves.size() ; i++) {
        std::shared_ptr<piece> _piece = moves.at(i).first;
        std::pair<int,int> toPos = moves.at(i).second;
        std::shared_ptr<state> _nextState = _state.nextState(_piece,toPos);
        int score = alphabeta(*_nextState,depth-1,!(isMax),alpha,beta)._score;
        eval_result.push_back(AB_result(score,_piece,toPos));
        if(isMax){
            alpha = std::max(alpha,score);
            if(beta <= alpha){
                return eval_result.back();
            }
        }
        else{
            beta = std::min(beta,score);
            if (beta <= alpha){
              return eval_result.back();
            }
        }
    }

    std::vector<int> scores;
        for(unsigned int i=0;i<eval_result.size();i++)
        {
            scores.push_back(eval_result.at(i)._score);
        }

        int index=0;
        if(isMax)
        {
            int maxScore = *std::max_element(scores.begin (),scores.end ());
            index = int (std::find(scores.begin(),scores.end(),maxScore) - scores.begin() );
        }

        else
        {
            int minScore = *std::min_element(scores.begin (),scores.end ());
            index = int (std::find(scores.begin(),scores.end(),minScore) - scores.begin() );

        }
    return eval_result.at (unsigned(index));
}



