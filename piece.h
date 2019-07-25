#ifndef PIECE_H
#define PIECE_H
#include <string>
#include <utility>

typedef struct point{
    point(int _row,int _col):row(_row),col(_col){}
    int row;
    int col;
}point;

class piece
{
public:
   piece();
   ~piece();
   piece(std::string name,std::pair<int,int> position,int team);

   std::pair<int, int> getPosition() ;
   std::string getName() ;
   void movePiece(std::pair<int,int> position);
   int getTeam() const;

private:
   std::string name;
   std::pair<int,int> position;  // pair (Y,X) --Row,Column
   int team;

};

#endif // PIECE_H
