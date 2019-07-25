#include "piece.h"

piece::piece()
{
    name = " ";
    position = std::make_pair(0,0);
}

piece::~piece()
{

}

piece::piece(std::string name, std::pair<int, int> position, int team)
{
   this->name = name;
   this->position = position;
   this->team = team;
}

std::pair<int, int> piece::getPosition()
{
    return position;
}

std::string piece::getName()
{
    return name;
}

void piece::movePiece(std::pair<int, int> position)
{
    this->position = position;
}

int piece::getTeam() const
{
    return team;
}

