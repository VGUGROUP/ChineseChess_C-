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

        for (int var = inputPiecePosition.second-1; var > col_of_piece_on_row ; --var) {
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
     if(inputPiecePosition.first + 2 <= maxRow){
         auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second ));
         if(result == boardState.end())
         {
             result = boardState.find(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second +1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end() && inputPiecePosition.second + 1 <= maxCol)
             {
                legalMoves.push_back(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second + 1));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second - 1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end() && inputPiecePosition.second - 1 >= maxCol)
             {
                legalMoves.push_back(std::make_pair(inputPiecePosition.first + 2,inputPiecePosition.second - 1));
             }
         }
     }
     //up
     if(inputPiecePosition.first - 2 >= minRow){
         auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second ));
         if(result == boardState.end())
         {
             result = boardState.find(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second +1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end() && inputPiecePosition.second + 1 <= maxCol)
             {
               legalMoves.push_back(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second + 1));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first - 2,inputPiecePosition.second - 1));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end() && inputPiecePosition.second + 1 >= minCol)
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
             else if (result == boardState.end() && inputPiecePosition.first + 1 <= maxRow)
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second - 2));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second - 2));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end() && inputPiecePosition.first - 1 >= minRow)
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
             else if (result == boardState.end() && inputPiecePosition.first + 1 <= maxRow)
             {
                 legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1,inputPiecePosition.second + 2));
             }

             result = boardState.find(std::make_pair(inputPiecePosition.first - 1,inputPiecePosition.second + 2));
             if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
             {
                legalMoves.push_back(result->first);
             }
             else if (result == boardState.end() && inputPiecePosition.first + 1 >= minRow)
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
    int team = _piece->getTeam();

    //up
    auto result = findFirstPieceOnCol(_piece->getPosition(),boardState,false);
    if( result != nullptr)
    {
        for (int var = inputPiecePosition.first - 1; var > result->getPosition().first ; --var) {
            legalMoves.push_back(std::make_pair(var,_piece->getPosition().second));
        }
        if(result->getTeam() != team ){
            legalMoves.push_back(result->getPosition());
        }

    }
    else{
        for (int var = inputPiecePosition.first - 1; var >= minRow; --var) {
            legalMoves.push_back((std::make_pair(var,inputPiecePosition.second)));
        }
    }
    //down
    result = findFirstPieceOnCol(_piece->getPosition(),boardState,true);
    if( result != nullptr)
    {
        for (int var = inputPiecePosition.first + 1; var < result->getPosition().first ; ++var) {
            legalMoves.push_back(std::make_pair(var,_piece->getPosition().second));
        }
        if(result->getTeam() != team ){
            legalMoves.push_back(result->getPosition());
        }
    }
    else{
        for (int var = inputPiecePosition.first + 1; var <= maxRow; ++var) {
            legalMoves.push_back((std::make_pair(var,inputPiecePosition.second)));
        }
    }
    //right
    result = findFirstPieceOnRow(_piece->getPosition(),boardState,true);
    if( result != nullptr)
    {
        for (int var = inputPiecePosition.second + 1; var < result->getPosition().second ; ++var) {
            legalMoves.push_back(std::make_pair(_piece->getPosition().first,var));
        }
        if(result->getTeam() != team ){
            legalMoves.push_back(result->getPosition());
        }
    }
    else{
        for (int var = inputPiecePosition.second + 1; var <= maxCol; ++var) {
            legalMoves.push_back((std::make_pair(inputPiecePosition.first,var)));
        }
    }
    //left
    result = findFirstPieceOnRow(_piece->getPosition(),boardState,false);
    if( result != nullptr)
    {
        for (int var = inputPiecePosition.second - 1; var > result->getPosition().second ; --var) {
            legalMoves.push_back(std::make_pair(_piece->getPosition().first,var));
        }
        if(result->getTeam() != team ){
            legalMoves.push_back(result->getPosition());
        }
    }
    else{
        for (int var = inputPiecePosition.second - 1; var >= minCol; --var) {
            legalMoves.push_back((std::make_pair(inputPiecePosition.second,var)));
        }
    }
    return  legalMoves;
}
std::vector<std::pair<int, int> > rule::possibleMoveForElephant(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
    std::vector<std::pair<int, int>> legalMoves;
    std::pair<int, int> inputPiecePosition(_piece->getPosition());
    //up left
    if((inputPiecePosition.first - 2 >= minRow && inputPiecePosition.second - 2 >= minCol && inputPiecePosition.first + 1 <= minRow + 4 ) ||
       (inputPiecePosition.first - 2 >= maxRow - 4 && inputPiecePosition.second - 2 >= minCol))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second - 1 ));
        if(result == boardState.end()) // Blank pos 1 step up left
        {
            result = boardState.find({inputPiecePosition.first -2, inputPiecePosition.second - 2 });
            if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
            {
               legalMoves.push_back(result->first);
            }
            else if (result == boardState.end())
            {
                legalMoves.push_back(std::make_pair(inputPiecePosition.first - 2, inputPiecePosition.second - 2 ));
            }
        }
    }
    //up right
    if((inputPiecePosition.first - 2 >= minRow && inputPiecePosition.second + 2 <= maxCol && inputPiecePosition.first + 1 <= minRow + 4 ) ||
       (inputPiecePosition.first - 2 >= maxRow - 4 && inputPiecePosition.second + 2 <= maxCol))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second + 1 ));
        if(result == boardState.end()) // Blank pos 1 step up left
        {
            result = boardState.find(std::make_pair(inputPiecePosition.first -2, inputPiecePosition.second + 2 ));
            if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
            {
               legalMoves.push_back(result->first);
            }
            else if (result == boardState.end())
            {
                legalMoves.push_back(std::make_pair(inputPiecePosition.first - 2, inputPiecePosition.second + 2 ));
            }
        }
    }
    //down left
    if((inputPiecePosition.first + 2 <= minRow + 4 && inputPiecePosition.second - 2 >= minCol ) ||
       (inputPiecePosition.first + 2 <= maxRow && inputPiecePosition.second - 2 >= minCol && inputPiecePosition.first - 1 >= maxRow - 4 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second - 1 ));
        if(result == boardState.end()) // Blank pos 1 step up left
        {
            result = boardState.find({inputPiecePosition.first + 2, inputPiecePosition.second - 2 });
            if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
            {
               legalMoves.push_back(result->first);
            }
            else if (result == boardState.end())
            {
                legalMoves.push_back(std::make_pair(inputPiecePosition.first + 2, inputPiecePosition.second - 2 ));
            }
        }

    }
    //down right
    if((inputPiecePosition.first + 2 <= minRow + 4 && inputPiecePosition.second + 2 <= maxCol ) ||
       (inputPiecePosition.first + 2 <= maxRow && inputPiecePosition.second + 2 <= maxCol && inputPiecePosition.first - 1 >= maxRow - 4 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second + 1 ));
        if(result == boardState.end()) // Blank pos 1 step up left
        {
            result = boardState.find({inputPiecePosition.first + 2, inputPiecePosition.second + 2 });
            if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
            {
               legalMoves.push_back(result->first);
            }
            else if (result == boardState.end())
            {
                legalMoves.push_back(std::make_pair(inputPiecePosition.first + 2, inputPiecePosition.second + 2 ));
            }
        }
    }
    return legalMoves;
}
std::vector<std::pair<int, int> > rule::possibleMoveForAdvisor(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
    std::vector<std::pair<int, int>> legalMoves;
    std::pair<int, int> inputPiecePosition(_piece->getPosition());

    //up left
    if( (inputPiecePosition.first - 1 >= minRow && inputPiecePosition.second - 1 >= minCol + 3 ) ||
        (inputPiecePosition.first - 1 >= maxRow - 2 && inputPiecePosition.second - 1 >= minCol + 3 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1 , inputPiecePosition.second - 1 ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second - 1 ));
        }
    }
    //up right
    if( (inputPiecePosition.first - 1 >= minRow && inputPiecePosition.second + 1 <= maxCol - 3 ) ||
        (inputPiecePosition.first - 1 >= maxRow - 2 && inputPiecePosition.second + 1 <= maxCol - 3 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1 , inputPiecePosition.second + 1 ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second + 1 ));
        }
    }
    //down left
    if( (inputPiecePosition.first + 1 <= minRow + 2 && inputPiecePosition.second - 1 >= minCol + 3 ) ||
        (inputPiecePosition.first + 1 <= maxRow && inputPiecePosition.second - 1 >= minCol + 3 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1 , inputPiecePosition.second - 1 ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second - 1 ));
        }
    }
    //down right
    if( (inputPiecePosition.first + 1 >= minRow + 2 && inputPiecePosition.second + 1 <= maxCol - 3 ) ||
        (inputPiecePosition.first + 1 >= maxRow && inputPiecePosition.second + 1 <= maxCol - 3 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1 , inputPiecePosition.second + 1 ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second + 1 ));
        }
    }
    return legalMoves;
}

std::vector<std::pair<int, int> > rule::possibleMoveForGeneral(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
    std::vector<std::pair<int, int>> legalMoves;
    std::pair<int, int> inputPiecePosition(_piece->getPosition());

    //up
    if( (inputPiecePosition.first - 1 >= minRow ) || (inputPiecePosition.first - 1 >= maxRow - 2 ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1 , inputPiecePosition.second ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second ));
        }
    }
    //down
    if( (inputPiecePosition.first + 1 <= minRow + 2 ) || (inputPiecePosition.first + 1 <= maxRow ))
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1 , inputPiecePosition.second ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second ));
        }
    }
    //left
    if( inputPiecePosition.second - 1 >= minCol + 3 )
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first, inputPiecePosition.second - 1 ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first, inputPiecePosition.second - 1 ));
        }
    }
    //right
    if( inputPiecePosition.second + 1 <= maxCol - 3 )
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first, inputPiecePosition.second + 1 ));
        // Capture piece pos condition:
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first, inputPiecePosition.second + 1 ));
        }
    }
    return legalMoves;
}

std::vector<std::pair<int, int> > rule::possibleMoveForSoldier(std::shared_ptr<piece> &_piece, std::map<std::pair<int, int>, std::shared_ptr<piece> > boardState)
{
    std::vector<std::pair<int, int>> legalMoves;
    std::pair<int, int> inputPiecePosition(_piece->getPosition());
    //down black
    if(_piece->getTeam()== -1 && inputPiecePosition.first + 1 <= maxRow )
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second ));
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first + 1, inputPiecePosition.second ));
        }
    }
    //left black after river
    if(_piece->getTeam()== -1 && inputPiecePosition.first >= maxRow - 4 && inputPiecePosition.second - 1 >= minCol)
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first, inputPiecePosition.second - 1 ));
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first , inputPiecePosition.second - 1 ));
        }
    }
    //right black after river
    if(_piece->getTeam()== -1 && inputPiecePosition.first >= maxRow - 4 && inputPiecePosition.second + 1 <= maxCol)
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first, inputPiecePosition.second + 1 ));
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first, inputPiecePosition.second +1 ));
        }
    }
    //up red
    if(_piece->getTeam()== 1 && inputPiecePosition.first - 1 >= minRow )
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second ));
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first - 1, inputPiecePosition.second ));
        }
    }
    //left red after river
    if(_piece->getTeam()== 1 && inputPiecePosition.first <= minRow + 4 && inputPiecePosition.second - 1 >= minCol)
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first, inputPiecePosition.second - 1 ));
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first , inputPiecePosition.second - 1 ));
        }
    }
    //right red after river
    if(_piece->getTeam()== 1 && inputPiecePosition.first <= minRow + 4 && inputPiecePosition.second + 1 >= maxCol)
    {
        auto result = boardState.find(std::make_pair(inputPiecePosition.first, inputPiecePosition.second + 1 ));
        if ( result != boardState.end() && result->second->getTeam() != _piece->getTeam())
        {
           legalMoves.push_back(result->first);
        }
        // Blank pos condition:
        else if (result == boardState.end())
        {
            legalMoves.push_back(std::make_pair(inputPiecePosition.first , inputPiecePosition.second + 1 ));
        }
    }
    return legalMoves;
}


