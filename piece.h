#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <utility>


class piece
{
public:
   piece();
   ~piece();
   piece(piece &_piece);
   piece(std::string name, std::pair<int,int> position, int team, std::string symbol);

   std::pair<int, int> getPosition() ;
   std::string getName() ;
   void movePiece(std::pair<int,int> position);
   int getTeam() const;
   std::string getSymbol() const;

private:
   std::string name,symbol;
   std::pair<int,int> position;  // pair (Y,X) --Row,Column
   int team;


};

#endif // PIECE_H
