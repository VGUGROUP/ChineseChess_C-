#include "player.h"

player::player()
{
    createRedPiece();
    for(auto &piece : RedPiece){
        std::cout<< piece.get()->getName() << std::endl;
    }
    createBlackPiece();
}

void player::createBlackPiece()
{
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackCar",std::pair<int,int>(1,1),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackHorse",std::pair<int,int>(1,2),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackAdvisor",std::pair<int,int>(1,3),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackServant",std::pair<int,int>(1,4),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackGen",std::pair<int,int>(1,5),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackServant",std::pair<int,int>(1,6),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackAdvisor",std::pair<int,int>(1,7),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackBlackHorse",std::pair<int,int>(1,8),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackCar",std::pair<int,int>(1,9),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackCannon",std::pair<int,int>(3,2),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackCannon",std::pair<int,int>(3,8),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,1),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,3),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,5),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,7),BLACK)));
    BlackPiece.push_back(std::unique_ptr<piece>(new piece("BlackSoldier",std::pair<int,int>(4,9),BLACK)));

}

void player::createRedPiece()
{
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedCar",std::pair<int,int>(10,1),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedHorse",std::pair<int,int>(10,2),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedAdvisor",std::pair<int,int>(10,3),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedServant",std::pair<int,int>(10,4),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedGen",std::pair<int,int>(10,5),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedServant",std::pair<int,int>(10,6),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedAdvisor",std::pair<int,int>(10,7),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedRedHorse",std::pair<int,int>(10,8),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedCar",std::pair<int,int>(10,9),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedCannon",std::pair<int,int>(7,1),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedCannon",std::pair<int,int>(7,3),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,5),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,7),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(7,9),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(8,2),RED)));
    RedPiece.push_back(std::unique_ptr<piece>(new piece("RedSoldier",std::pair<int,int>(8,8),RED)));

}

