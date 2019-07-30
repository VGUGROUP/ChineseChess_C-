#include "state.h"

state::state()
{

}

state::state(state &_state)
{
    this->_player = std::shared_ptr<player> (new player(*_state.getPlayer()));
}

void state::restart()
{
    _player->restart();
}

bool state::setNextMove_AB()
{
    if(!isEndGame()){
        auto result = alphabeta(*this,3,false,-9999,9999);

//        std::cout<<result._piece->getSymbol()<<"_row_"<<result._toPoint.first<<"_col_"<<result._toPoint.second<<std::endl;
        movePiece(result._piece,result._toPoint);
        draw_state(*this);
        switchPlayer();
        return  true;
    }
    return false;
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
    NAME:
    std::string symbol,row,col;
    std::pair<int,int> position;
    std::cout <<"input piece symbol:";
    std::getline(std::cin,symbol);
    auto piece = _player->getPiecBySymbol(symbol);
    if(piece == nullptr){
        std::cout<<"invalid name"<<std::endl;
        goto NAME;
    }
    auto list = _player->getMoveByPiece(piece);
    for (auto var : list) {
       std::cout<<"Row_"<<var.first<<"Col_"<<var.second<<std::endl;
    }

    POS:
    std::cout<<"input position: "<<std::endl;
    std::cout<<"Row: ";
    std::getline(std::cin,row);
    std::cout<<"Col: ";
    std::getline(std::cin,col);

    if(row.empty() || col.empty()) goto POS;
    position = {std::stoi(row),std::stoi(col)};
    auto it = std::find(list.begin(),list.end(),position);
    if(it == list.end()){
        std::cout<<"invalid position"<<std::endl;
        goto POS;
    };
    movePiece(piece,position);

    draw_state(*this);
   
}

void state::playGame()
{
    START:
    do{
     inputMove();
    }while(setNextMove_AB());

    std::cout<<"game is end"<<std::endl;
    std::cout<<"press CTRL D to restart";
    std::string _restart;
    std::cin.clear();
    std::getline(std::cin,_restart);
    if(!std::cin.eof()) {
        restart();
        goto START;
    }


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
//    //------------------------------------------------
//    for (auto var : moves) {
//        std::cout<<var.first->getSymbol()<<"_Row_"<<var.second.first<<"_Col_"<<var.second.second<<std::endl;
//    }
//    //------------------------------------------------

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
//    std::cout<<eval_result.at(index)._piece->getSymbol()<<"_row_"<<eval_result.at(index)._toPoint.first
//            <<"_col_"<<eval_result.at(index)._toPoint.second<<std::endl;
    return eval_result.at (unsigned(index));
}



