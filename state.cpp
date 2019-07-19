#include "state.h"

state::state()
{

}

std::vector<piece>& state::getBlackPiece() const
{
    return BlackPiece;
}

std::vector<piece>& state::getRedPiece() const
{
    return RedPiece;
}
