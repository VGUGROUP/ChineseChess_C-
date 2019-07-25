#include "rule.h"

rule::rule()
{

}

std::shared_ptr<piece> rule::findFirstPieceOnRow(std::pair<int, int> currentPosition,
                                std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState,
                                bool increasing)
{
    int col = currentPosition.second;
    do{
        if(increasing) col++;
        else  col--;

        auto _piece = boardState.find(std::make_pair(currentPosition.first,col)); //pair(row,col)
        if(_piece != boardState.end())
        {
            return  _piece->second;
        }
    } while (col >= minCol && col <= maxCol);

    return  nullptr;
}

std::shared_ptr<piece> rule::findFirstPieceOnCol(std::pair<int, int> currentPosition, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState, bool increasing)
{
    int row = currentPosition.first;
    do
    {
        if(increasing) row++;
        else  row--;
        auto _piece = boardState.find(std::make_pair(row,currentPosition.second));
        if(_piece != boardState.end())
        {
            return _piece->second;
        }

    } while (row >= minRow && row <= maxRow);

    return nullptr;
}

std::vector<std::pair<int, int> > rule::possibleMoveForCannon(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
    std::vector<std::pair<int,int>> legalMoves;
    std::pair<int,int> inputPiecePosition(_piece->getPosition());

    //find lower row
    auto result = findFirstPieceOnCol(inputPiecePosition,boardState,true);
    if( result != nullptr)
    {
        int row_of_piece_on_col = result.get()->getPosition().first;

        for (int var = inputPiecePosition.first+1; var < row_of_piece_on_col ; ++var) {
            legalMoves.push_back(std::make_pair(var,inputPiecePosition.second));
        }

        result = findFirstPieceOnCol(result->getPosition(),boardState,true);
        if( result && result.get()->getTeam() != _piece->getTeam() )
        {
            legalMoves.push_back(result->getPosition());
        }
    }
    else
    {
        for (int i = inputPiecePosition.first +1 ;i >= minRow ; i++) {
            legalMoves.push_back(std::make_pair(i,inputPiecePosition.second));
        }
    }
    //find upper row
    result = findFirstPieceOnCol(inputPiecePosition,boardState,false);
    if( result != nullptr)
    {
        int row_of_piece_on_col = result.get()->getPosition().first;

        for (int var = inputPiecePosition.first-1; var > row_of_piece_on_col ; --var) {
            legalMoves.push_back(std::make_pair(var,inputPiecePosition.second));
        }

        result = findFirstPieceOnCol(result->getPosition(),boardState,false);
        if( result && result.get()->getTeam() != _piece->getTeam() )
        {
            legalMoves.push_back(result->getPosition());
        }
    }
    else
    {
        for (int i = inputPiecePosition.first -1 ;i <= minRow ; i--) {
            legalMoves.push_back(std::make_pair(i,inputPiecePosition.second));
        }
    }
    //find right col
    result = findFirstPieceOnRow(inputPiecePosition,boardState,true);
    if( result != nullptr)
    {
        int col_of_piece_on_row = result.get()->getPosition().second;

        for (int var = inputPiecePosition.second+1; var < col_of_piece_on_row ; ++var) {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first,var));
        }

        result = findFirstPieceOnRow(result->getPosition(),boardState,true);
        if( result && result.get()->getTeam() != _piece->getTeam() )
        {
            legalMoves.push_back(result->getPosition());
        }
    }

    else
    {
        for (int i = inputPiecePosition.second + 1;i <= maxCol; i++) {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first,i));
        }
    }
    //find left col
    result = findFirstPieceOnRow(inputPiecePosition,boardState,false);
    if( result != nullptr)
    {
        int col_of_piece_on_row = result.get()->getPosition().second;

        for (int var = inputPiecePosition.second-1; var < col_of_piece_on_row ; --var) {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first,var));
        }

        result = findFirstPieceOnRow(result->getPosition(),boardState,true);
        if( result && result.get()->getTeam() != _piece->getTeam() )
        {
            legalMoves.push_back(result->getPosition());
        }
    }
    else
    {
        for (int i = inputPiecePosition.second - 1;i>=minCol; i--) {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first,i));
        }
    }
    return legalMoves;
}

std::vector<std::pair<int, int> > rule::possibleMoveForHorse(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
     std::vector<std::pair<int,int>> legalMoves;
     std::pair<int,int> inputPiecePosition(_piece->getPosition());

     //down
     if(inputPiecePosition.first + 2 >= maxRow){
         auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second ));
         if(result == boardState.end())
         {
             result = boardState.find(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second +1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second + 1));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second - 1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second - 1));
             }
         }
     }
     //up

     //down
     if(inputPiecePosition.first - 2 <= minRow){
         auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second ));
         if(result == boardState.end())
         {
             result = boardState.find(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second +1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second + 1));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second - 1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second - 1));
             }
         }
     }
     //left
     if(inputPiecePosition.second - 2 >= minCol){
         auto result = boardState.find(std::make_pair(inputPiecePosition.first,inputPiecePosition.second - 1 ));
         if(result == boardState.end())
         {
             result = boardState.find(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second - 2));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second - 2));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second - 2));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second - 2));
             }
         }
     }
     //right
     if(inputPiecePosition.second + 2 <= maxCol){
         auto result = boardState.find(std::make_pair(inputPiecePosition.first,inputPiecePosition.second + 1 ));
         if(result == boardState.end())
         {
             result = boardState.find(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second + 2));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second + 2));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second + 2));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end())
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second + 2));
             }
         }
     }
     return  legalMoves;
}

std::vector<std::pair<int, int> > rule::possibleMoveForCar(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
    std::vector<std::pair<int,int>> legalMoves;
    std::pair<int,int> inputPiecePosition(_piece->getPosition());

    //up
    auto result = findFirstPieceOnCol(_piece->getPosition(),boardState,true);
    if( result != nullptr && result->getTeam() != _piece->getTeam())
    {
        for (int var = 0; var <= result->getPosition().first ; ++var) {
            legalMoves.push_back(std::make_pair(var,_piece->getPosition().second));
        }
    }
    else {

    }
    //down
    //right
    //left

}


