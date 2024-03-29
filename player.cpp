#include "player.h"

player::player()
{
    createRedPiece();
    createBlackPiece();
    update_boardState();
}

player::player(player &_player)
{
    this->currentPlayer = _player.getCurrentPlayer();
    for (auto _piece : _player.getRedPiece()) {
        RedPiece.push_back(std::shared_ptr<piece>(new piece(*_piece.get())));
    }
    for (auto _piece : _player.getBlackPiece()) {
        BlackPiece.push_back(std::shared_ptr<piece>(new piece(*_piece.get())));
    }
    update_boardState();
}

void player::createBlackPiece()
{
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCar",std::pair<int,int>(1,1),BLACK,"BC1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackHorse",std::pair<int,int>(1,2),BLACK,"BH1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackElephant",std::pair<int,int>(1,3),BLACK,"BE1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackAdvisor",std::pair<int,int>(1,4),BLACK,"BA1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackGen",std::pair<int,int>(1,5),BLACK,"BG1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackAdvisor",std::pair<int,int>(1,6),BLACK,"BA1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackElephant",std::pair<int,int>(1,7),BLACK,"BE2")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackHorse",std::pair<int,int>(1,8),BLACK,"BH2")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCar",std::pair<int,int>(1,9),BLACK,"BC2")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCannon",std::pair<int,int>(3,2),BLACK,"BO1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCannon",std::pair<int,int>(3,8),BLACK,"BO2")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,1),BLACK,"BS1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,3),BLACK,"BS2")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,5),BLACK,"BS3")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,7),BLACK,"BS4")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,9),BLACK,"BS5")));

}

void player::createRedPiece()
{
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCar",std::pair<int,int>(10,1),RED,"RC1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedHorse",std::pair<int,int>(10,2),RED,"RH1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedElephant",std::pair<int,int>(10,3),RED,"RE1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedAdvisor",std::pair<int,int>(10,4),RED,"RA1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedGen",std::pair<int,int>(10,5),RED,"RG1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedAdvisor",std::pair<int,int>(10,6),RED,"RA2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedElephant",std::pair<int,int>(10,7),RED,"RE2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedHorse",std::pair<int,int>(10,8),RED,"RH2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCar",std::pair<int,int>(10,9),RED,"RC2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCannon",std::pair<int,int>(8,2),RED,"RO1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCannon",std::pair<int,int>(8,8),RED,"RO2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,1),RED,"RS1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,3),RED,"RS2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,5),RED,"RS3")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,7),RED,"RS4")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,9),RED,"RS5")));

}

void player::update_boardState()
{
    boardState.clear();
    for(std::shared_ptr<piece> _piece : RedPiece)
    {
        boardState.insert({_piece->getPosition(),_piece});
    }

    for(std::shared_ptr<piece> _piece : BlackPiece)
    {
        boardState.insert({_piece->getPosition(),_piece});
    }
}

bool player::movePiece(std::shared_ptr<piece> &_piece, std::pair<int, int> position)
{
    if(isValidMove(_piece,position,boardState)){
        _piece.get()->movePiece(position);
        capture(position);
        update_boardState();
        return  true;
    }
    return false;

}

void player::capture(std::pair<int, int> position)
{
/*      auto result = boardState.find(std::make_pair(10,1));
      getValueOfState();
//      auto moves = possibleMoveForHorse(RedPiece[1],boardState);
      for (auto var : possibleMoves) {
          std::cout<< var.first.get()->getSymbol()<<"   Row_"<<var.second.first<<"Col_"<<var.second.second<<std::endl;
      }
     //...*/
    if(currentPlayer == BLACK){
        RedPiece.erase(std::remove_if(RedPiece.begin(),RedPiece.end(),
           [position](std::shared_ptr<piece> &_piece)
           {

             if(_piece.get()->getPosition() == position)
             {
               return  true;
             }
             return false;
           }
           ),RedPiece.end()
        );

    }
    else if (currentPlayer == RED) {
       BlackPiece.erase(std::remove_if(BlackPiece.begin(),BlackPiece.end(),
           [position](std::shared_ptr<piece> &_piece)
           {
             if(_piece.get()->getPosition() == position)
             {

               return  true;
             }
             return false;
           }
           ),BlackPiece.end()
        );
    }
}

std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > >player::computelegalMoves()
{
        std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
        if(currentPlayer == RED){
           pieceList.assign(RedPiece.begin(),RedPiece.end());
        }
        else if (currentPlayer == BLACK) {
            pieceList.assign(BlackPiece.begin(),BlackPiece.end());
        }
        possibleMoves.clear();
        for (auto piece : pieceList) {
            std::string name = piece.get()->getName();

            if(name == "BlackCar" || name == "RedCar"){
                auto list = possibleMoveForCar(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }
            if(name == "BlackHorse" || name == "RedHorse"){
                auto list = possibleMoveForHorse(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }
            if(name == "BlackCannon" || name == "RedCannon"){
                auto list = possibleMoveForCannon(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }
            if(name == "BlackSoldier" || name == "RedSoldier"){
                auto list = possibleMoveForSoldier(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }
            if(name == "BlackElephant" || name == "RedElephant"){
                auto list = possibleMoveForElephant(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }
            if(name == "BlackAdvisor" || name == "RedAdvisor"){
                auto list = possibleMoveForAdvisor(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }
            if(name == "BlackGen" || name == "RedGen"){
                auto list = possibleMoveForGeneral(piece,boardState);
                for (auto point : list) {
                       possibleMoves.push_back({piece,point});
                }
            }


        }
        return  possibleMoves;
}

std::map<std::pair<int, int>, std::shared_ptr<piece> > player::getBoardState()
{
    return boardState;
}

int player::getCurrentPlayer() const
{
    return currentPlayer;
}

int player::getValueOfState()
{
    int RedScore = 0 ,BlackScore = 0;
    for (auto &piece : RedPiece) {
        std::string name = piece->getName();
        RedScore += pieceValue(name) + positionValue(name,piece->getPosition());

    }
    for (auto &piece : BlackPiece) {
        std::string name = piece->getName();
        BlackScore += pieceValue(name) + positionValue(name,piece->getPosition());
    }

    return RedScore - BlackScore;
}

bool player::isKingExist(int currentPlayer)
{
    std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
    if(currentPlayer == BLACK){
       pieceList.assign(RedPiece.begin(),RedPiece.end());
    }
    else if (currentPlayer == RED) {
        pieceList.assign(BlackPiece.begin(),BlackPiece.end());
    }

   auto result = std::find_if(pieceList.begin(),pieceList.end(),[](std::shared_ptr<piece> &_piece){
        if(_piece->getName() == "RedGen" || _piece->getName() == "BlackGen"){
           return true;
        }

        else {
            return false;
        }

    });

   if(result == pieceList.end()) return false;
   return  true;
}

void player::restart()
{
    RedPiece.clear();
    BlackPiece.clear();
    createRedPiece();
    createBlackPiece();
    update_boardState();
}

std::shared_ptr<piece> player::getSimilarPiece(std::shared_ptr<piece> &_piece)
{
    int player = _piece->getTeam();
    std::string symbol = _piece->getSymbol();

    std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
    if(player == RED){
       pieceList.assign(RedPiece.begin(),RedPiece.end());
    }
    else if (player == BLACK) {
        pieceList.assign(BlackPiece.begin(),BlackPiece.end());
    }

    auto result = std::find_if(pieceList.begin(),pieceList.end(),[symbol](std::shared_ptr<piece> &_piece){
         if(_piece->getSymbol() == symbol){
            return true;
         }

         else {
             return false;
         }

     });


    if(result != pieceList.end()) return result->get();

    return std::shared_ptr<piece>(nullptr);

}

std::shared_ptr<piece> player::getPiecBySymbol(std::string symbol)
{
    std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
    if(currentPlayer == RED){
       pieceList.assign(RedPiece.begin(),RedPiece.end());
    }
    else if (currentPlayer == BLACK) {
        pieceList.assign(BlackPiece.begin(),BlackPiece.end());
    }

    auto result = std::find_if(pieceList.begin(),pieceList.end(),[symbol](std::shared_ptr<piece> &_piece){
         if(_piece->getSymbol() == symbol){
            return true;
         }

         else {
             return false;
         }

     });


    if(result != pieceList.end()) return result->get();
    return std::shared_ptr<piece>(nullptr);
}

void player::setCurrentPlayer(int value)
{
    currentPlayer = value;
}

void player::setBlackPiece(const std::vector<std::shared_ptr<piece> > &value)
{
    BlackPiece = value;
}

void player::setRedPiece(const std::vector<std::shared_ptr<piece> > &value)
{
    RedPiece = value;
}

std::vector<std::shared_ptr<piece> > player::getRedPiece() const
{
    return RedPiece;
}

std::vector<std::shared_ptr<piece> > player::getBlackPiece() const
{
    return BlackPiece;
}

std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > > player::getPossibleMoves() const
{
    return possibleMoves;
}

std::vector<std::pair<int, int> > player::getMoveByPiece(std::shared_ptr<piece> &piece)
{
    std::string name = piece.get()->getName();
    possibleMoves.clear();
    if(name == "BlackCar" || name == "RedCar"){
        return  possibleMoveForCar(piece,boardState);
    }
    if(name == "BlackHorse" || name == "RedHorse"){
        return  possibleMoveForHorse(piece,boardState);

    }
    if(name == "BlackCannon" || name == "RedCannon"){
        return  possibleMoveForCannon(piece,boardState);

    }
    if(name == "BlackSoldier" || name == "RedSoldier"){
        return  possibleMoveForSoldier(piece,boardState);

    }
    if(name == "BlackElephant" || name == "RedElephant"){
        return  possibleMoveForElephant(piece,boardState);

    }
    if(name == "BlackAdvisor" || name == "RedAdvisor"){
        return  possibleMoveForAdvisor(piece,boardState);

    }
    if(name == "BlackGen" || name == "RedGen"){
        return  possibleMoveForGeneral(piece,boardState);
    }
}


