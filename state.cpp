#include "state.h"

state::state()
{

}

state::state(state &_state)
{
   this->_player = std::shared_ptr<player> (new player(*_state.getPlayer()));
}

bool state::isEndGame()
{
    auto currentPlayer = _player->getCurrentPlayer();
    bool result = _player->isKingExist(currentPlayer);
    return  result;
}

void state::initGameState()
{
    _player = std::shared_ptr<player> (new player);
    _player->setCurrentPlayer(RED);
    auto result = _player->getRedPiece()[0];
    nextState(result,{8,1});

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
    _nextState->switchPlayer();
    auto nextstate_piece = _nextState->getPlayer()->getSimilarPiece(_piece);
    _nextState->movePiece(nextstate_piece,position);
    draw_state(*_nextState);
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

void state::movePiece(std::shared_ptr<piece> &_piece, std::pair<int, int> position)
{
    this->_player->movePiece(_piece,position);
}



