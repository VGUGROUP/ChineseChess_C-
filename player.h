#ifndef PLAYER_H
#define PLAYER_H

#define RED 1
#define BLACK -1

#include <vector>
#include <piece.h>
#include <utility>
#include <map>
#include <memory>
#include <iostream>
#include <algorithm>
#include <rule.h>
#include <evaluation.h>

class player : public rule, public evaluation
{
public:
    player();
    player(player &_player);
    void createRedPiece();
    void createBlackPiece();
    void update_boardState();
    bool movePiece(std::shared_ptr<piece> &_piece,std::pair<int,int> position);
    void capture(std::pair<int,int> position);
    std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > > computelegalMoves();
    std::map<std::pair<int, int>, std::shared_ptr<piece> > getBoardState();
    int getCurrentPlayer() const;
    int getValueOfState();
    bool isKingExist(int currentPlayer);
    void restart();
    std::shared_ptr<piece> getSimilarPiece(std::shared_ptr<piece>& _piece);
    std::shared_ptr<piece> getPiecBySymbol(std::string symbol);
    void setCurrentPlayer(int value);
    void setBlackPiece(const std::vector<std::shared_ptr<piece> > &value);
    void setRedPiece(const std::vector<std::shared_ptr<piece> > &value);
    std::vector<std::shared_ptr<piece> > getRedPiece() const;
    std::vector<std::shared_ptr<piece> > getBlackPiece() const;
    std::vector<std::pair<std::shared_ptr<piece>, std::pair<int, int> > > getPossibleMoves() const;
     std::vector<std::pair<int, int> > getMoveByPiece(std::shared_ptr<piece> &_piece);

private:
    int currentPlayer = RED; //RED: user , BLACK: minimax , 0: undefined
    std::vector< std::shared_ptr<piece> > RedPiece,BlackPiece;
    // "boardState" list map position of each piece and piece object for ease to use in rule class
    std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState;
    std::vector<std::pair<std::shared_ptr<piece>,std::pair<int,int>>> possibleMoves;

};

#endif // PLAYER_H
