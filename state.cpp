#include "state.h"

state::state()
{

}

bool state::isEndGame()
{
    auto currentPlayer = _player->getCurrentPlayer();
    bool result = _player->isKingExist(currentPlayer);
    return  result;
}

void state::initGameState()
{
    _player = std::unique_ptr<player> (new player);
    _player->setCurrentPlayer(RED);
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
