#include "player.h"

player::player()
{
    currentPlayer = RED; //RED: user , BLACK: minimax
    createRedPiece();
    createBlackPiece();
    update_boardState();
}

void player::createBlackPiece()
{
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCar1",std::pair<int,int>(1,1),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackHorse1",std::pair<int,int>(1,2),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackAdvisor1",std::pair<int,int>(1,3),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackServant1",std::pair<int,int>(1,4),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackGen",std::pair<int,int>(1,5),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackServant2",std::pair<int,int>(1,6),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackAdvisor2",std::pair<int,int>(1,7),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackBlackHorse2",std::pair<int,int>(1,8),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCar2",std::pair<int,int>(1,9),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCannon1",std::pair<int,int>(3,2),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackCannon2",std::pair<int,int>(3,8),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier1",std::pair<int,int>(4,1),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier2",std::pair<int,int>(4,3),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier3",std::pair<int,int>(4,5),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier4",std::pair<int,int>(4,7),BLACK)));
    BlackPiece.push_back(std::shared_ptr<piece>(new piece("BlackSoldier5",std::pair<int,int>(4,9),BLACK)));

}

void player::createRedPiece()
{
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCar1",std::pair<int,int>(10,1),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedHorse1",std::pair<int,int>(10,2),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedAdvisor1",std::pair<int,int>(10,3),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedServant1",std::pair<int,int>(10,4),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedGen",std::pair<int,int>(10,5),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedServant2",std::pair<int,int>(10,6),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedAdvisor2",std::pair<int,int>(10,7),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedRedHorse2",std::pair<int,int>(10,8),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCar2",std::pair<int,int>(10,9),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCannon1",std::pair<int,int>(8,2),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedCannon2",std::pair<int,int>(8,8),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier1",std::pair<int,int>(7,1),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier2",std::pair<int,int>(7,3),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier3",std::pair<int,int>(7,5),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier4",std::pair<int,int>(7,7),RED)));
    RedPiece.push_back(std::shared_ptr<piece>(new piece("RedSoldier5",std::pair<int,int>(7,9),RED)));

}

void player::update_boardState()
{
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
}

void player::capture(std::pair<int, int> position)
{
      auto result = boardState.find(std::make_pair(8,2));
      auto moves = possibleMoveForCannon(result->second,boardState);
      for (auto var : moves) {
          std::cout<< var.first<<"_"<<var.second <<std::endl;
      }
//    std::vector<std::reference_wrapper< std::shared_ptr<piece>>> pieceList;
//    if(currentPlayer == BLACK){
//       pieceList.assign(RedPiece.begin(),RedPiece.end());
//    }
//    else if (currentPlayer == RED) {
//        pieceList.assign(BlackPiece.begin(),BlackPiece.end());
//    }

//    pieceList.erase(std::remove_if(pieceList.begin(),pieceList.end(),
//       [position](std::shared_ptr<piece> &_piece)
//       {

//         if(_piece.get()->getPosition() == position)
//         {
//           std::cout<<_piece->getName()<<"use_cout : "<<_piece.use_count()<<std::endl;
//           return  true;
//         }
//         return false;
//       }
//       )
//    );

}

