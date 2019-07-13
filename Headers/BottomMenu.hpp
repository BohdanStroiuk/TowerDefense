#pragma once
#include "../Headers/Cache.hpp"
#include "../Headers/Button.hpp"

class BottomMenu
{
private:
    Button* tower1Btn;
    Button* tower2Btn;
    Button* tower3Btn;

    Font* font;
    Text* levelInfo;
    Text* coinsInfo;
    Text* scoreInfo;

    bool towerSelected;
    string buildTowerType;

    

public:

    void reSelectTower();
    bool isSelectTower();

    void setLevelInfo(int);
    void setCoinsInfo(int);
    void setScoreInfo(int);

    string getSelectTowerType();

    void draw();
    void update();
    BottomMenu();
    ~BottomMenu();
};