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
    //    qDebug()<<"BlackHorse"<<BlackHorse[position.second/60-1][m_point.x()/60];
        return BlackHorse[position.second/60-1][position.first/60];
    }
    if(name =="RedHorse"){
     //    qDebug()<<"RedHorse"<<RedHorse[m_point.y()/60-1][m_point.x()/60];
        return RedHorse[position.second/60-1][position.first/60];
    }
    if(name =="BlackCannon"){
        return BlackCannon[position.second/60-1][position.first/60];
    }
    if(name =="RedCannon"){
        return RedCannon[position.second/60-1][position.first/60];
    }
    if(name =="RedCar"){
        return RedCar[position.second/60-1][position.first/60];
    }
    if(name =="BlackCar"){
        return BlackCar[position.second/60-1][position.first/60];
    }
    if(name =="RedSoldier"){
        return RedSoldier[position.second/60-1][position.first/60];
    }
    if(name =="BlackSoldier"){
        return BlackSoldier[position.second/60-1][position.first/60];
    }
    return 0;

}
