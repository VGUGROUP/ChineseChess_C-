
#ifndef RULE_H
#define RULE_H
#include <vector>
#include <algorithm>
#include <memory>
#include <map>
#include <iostream>
#include "piece.h"

class rule
{
public:
    rule();
    std::shared_ptr<piece> findFirstPieceOnRow(std::pair<int,int> currentPosition,
                              std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState,
                              bool increasing);
    std::shared_ptr<piece> findFirstPieceOnCol(std::pair<int,int> currentPosition,
                              std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState,
                              bool increasing);
    std::vector<std::pair<int,int>> possibleMoveForCannon(std::shared_ptr<piece>& _piece,
                                  std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState);
    std::vector<std::pair<int,int>> possibleMoveForHorse(std::shared_ptr<piece>& _piece,
                                  std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState);
    std::vector<std::pair<int,int>> possibleMoveForCar(std::shared_ptr<piece>& _piece,
                                  std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState);
    std::vector<std::pair<int,int>> possibleMoveForElephant(std::shared_ptr<piece>& _piece,
                                  std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState);
    std::vector<std::pair<int,int>> possibleMoveForAdvisor(std::shared_ptr<piece>& _piece,
                                  std::map<std::pair<int,int>, std::shared_ptr<piece>> boardState);


private:
    int maxRow = 10, minRow = 1, maxCol = 9 , minCol = 1;
    std::vector<std::pair<int,int> > moves;
};

#endif // RULE_H
