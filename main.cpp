#include<iostream>
#include<player.h>
#include<board_view.h>
using namespace std;

int main()
{
    player hah;
    hah.capture(std::pair<int,int> (10,1)); //Y,X
    board_view view1(hah.getBoardState());
    view1.draw_board();
    cout << "Hello World!" << endl;
    return 0;
}
