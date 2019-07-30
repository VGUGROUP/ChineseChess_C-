#include "piece.h"

piece::piece()
{
    name = " ";
    position = std::make_pair(0,0);
}

piece::~piece()
{

}

piece::piece(piece &_piece)
{
    this->name = _piece.getName();
    this->position = _piece.getPosition();
    this->team =_piece.getTeam();
    this->symbol = _piece.getSymbol();
}

piece::piece(std::string name, std::pair<int, int> position, int team, std::string symbol)
{
   this->name = name;
   this->position = position;
   this->team = team;
   this->symbol = symbol;
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

std::string piece::getSymbol() const
{
    return symbol;
}

