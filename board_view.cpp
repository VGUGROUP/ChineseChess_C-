#include "board_view.h"

board_view::board_view(std::map<std::pair<int, int>, std::shared_ptr<piece> > &_boardState)
{
    boardState = _boardState;
}

void board_view::draw_board()
{
    for (int row = 1; row <= 10; ++row) {
        for (int col = 1; col < 10; ++col) {
            auto result = boardState.find({row,col});
            if(result != boardState.end()){
                std::cout<<" "<<result->second->getSymbol()<<" ";
            }

            else {
                 std::cout<<"  *  ";
            }

        }
        std::cout<<std::endl;
    }
}
