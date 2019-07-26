#include "evaluation.h"

evaluation::evaluation()
{    
}

int evaluation::pieceValue(std::string name)
{
    if(name=="BlackGen"||name=="RedGen"){
        return 160000;
    }
    if(name=="BlackHorse"||name=="RedHorse"){
        return 270;
    }
    if(name=="BlackElephant"||name=="RedElephant"){
        return 120;
    }
    if(name =="BlackAdvisor"||name=="RedAdvisor"){
        return 120;
    }
    if(name =="BlackCannon"||name=="RedCannon"){
        return 285;
    }
    if(name == "BlackCar"||name=="RedCar"){
        return  600;
    }
    if(name =="BlackSoldier"||name=="RedSoldier"){
        return  30;
    }
    return 0;
}

int evaluation::positionValue(std::string name, std::pair<int, int> position)
{
    if(name == "BlackHorse"){
        return BlackHorse[position.first-1][position.second-1];
    }
    if(name =="RedHorse"){
        return RedHorse[position.first-1][position.second-1];
    }
    if(name =="BlackCannon"){
        return BlackCannon[position.first-1][position.second-1];
    }
    if(name =="RedCannon"){
        return RedCannon[position.first-1][position.second-1];
    }
    if(name =="RedCar"){
        return RedCar[position.first-1][position.second-1];
    }
    if(name =="BlackCar"){
        return BlackCar[position.first-1][position.second-1];
    }
    if(name =="RedSoldier"){
        return RedSoldier[position.first-1][position.second-1];
    }
    if(name =="BlackSoldier"){
        return BlackSoldier[position.first-1][position.second-1];
    }
    return 0;

}
