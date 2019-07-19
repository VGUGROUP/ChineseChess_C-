#include "piece.h"

piece::piece()
{
    name = " ";
    point = std::make_pair(0,0);
}

piece::piece(std::string name, std::pair<int, int> point, int team)
{
   this->name = name;
   this->point = point;
   this->team = team;
}
