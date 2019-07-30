#include "board_view.h"

board_view::board_view()
{

}

void board_view::draw_board(const std::shared_ptr<player> &_player)
{
    std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState = _player->getBoardState();
    for (int i = 1; i <=9; i++) {
        std::cout<<"   "<<i<<" ";
    }
    std::cout<<std::endl;

    for (int row = 1; row <= 10; ++row) {
        std::cout<<row;
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
        if (row == 5) {
            draw_river();
        }
    }
    std::cout<<"----------------------------------------------------------------------------"<<std::endl;
}

void board_view::draw_river()
{

    for(int row = 1 ;row <3; row++ ){
        for(int col = 1; col < 10; col++){
            std::cout<<"  ~~ ";
        }
         std::cout<<std::endl;
    }
}
