#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <utility>
#

class piece
{
public:
   piece();
   piece(std::string name,std::pair<int,int> point,int team);
   std::pair<int, int> getPoint() const;

private:
   std::string name;
   std::pair<int,int> point;
   int team;

};

#endif // PIECE_H
