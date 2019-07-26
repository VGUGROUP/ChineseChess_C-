#include "player.h"

player::player()
{
    createRedPiece();
    createBlackPiece();
    update_boardState();
}

void player::createBlackPiece()
{
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCar",std::pair<int,int>(1,1),BLACK,"BC1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackHorse",std::pair<int,int>(1,2),BLACK,"BH1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackAdvisor",std::pair<int,int>(1,3),BLACK,"BA1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackServant",std::pair<int,int>(1,4),BLACK,"BS1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackGen",std::pair<int,int>(1,5),BLACK,"BG1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackServant",std::pair<int,int>(1,6),BLACK,"BS1")));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackAdvisor",std::pair<int,int>(1,7),BLACK,"BA2")));
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
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedAdvisor",std::pair<int,int>(10,3),RED,"RA1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedServant",std::pair<int,int>(10,4),RED,"RS1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedGen",std::pair<int,int>(10,5),RED,"RG1")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedServant",std::pair<int,int>(10,6),RED,"RS2")));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedAdvisor",std::pair<int,int>(10,7),RED,"RA2")));
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

void player::movePiece(std::shared_ptr<piece> &_piece, std::pair<int, int> position)
{

    _piece.get()->movePiece(position);
    capture(position);
    update_boardState();
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
    std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
    if(currentPlayer == BLACK){
       pieceList.assign(RedPiece.begin(),RedPiece.end());
    }
    else if (currentPlayer == RED) {
        pieceList.assign(BlackPiece.begin(),BlackPiece.end());
    }

    pieceList.erase(std::remove_if(pieceList.begin(),pieceList.end(),
       [position](std::shared_ptr<piece> &_piece)
       {

         if(_piece.get()->getPosition() == position)
         {
           std::cout<<_piece->getName()<<"use_cout : "<<_piece.use_count()<<std::endl;
           return  true;
         }
         return false;
       }
       )
    );

}

void player::computelegalMoves()
{
        std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
        if(currentPlayer == BLACK){
           pieceList.assign(RedPiece.begin(),RedPiece.end());
        }
        else if (currentPlayer == RED) {
            pieceList.assign(BlackPiece.begin(),BlackPiece.end());
        }

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
        }
}

std::map<std::pair<int, int>, std::shared_ptr<piece> > &player::getBoardState()
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
        std::cout<<name+ " _ " <<pieceValue(name)<<" _ "<<positionValue(name,piece->getPosition())<<std::endl;
        RedScore = pieceValue(name) + positionValue(name,piece->getPosition());

    }
    for (auto &piece : BlackPiece) {
        std::string name = piece->getName();
        BlackScore = pieceValue(name) + positionValue(name,piece->getPosition());
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

void player::setCurrentPlayer(int value)
{
    currentPlayer = value;
}



