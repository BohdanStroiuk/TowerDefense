#pragma once
#include "../Headers/Map.hpp"
#include "../Headers/Cache.hpp"
#include <SFML/Graphics.hpp>
#include "../Headers/PathFinder.hpp"
#include "../Headers/Enemy.hpp"
#include "../Headers/Tower.hpp"
#include "../Headers/BottomMenu.hpp"

using namespace std;

class Level
{
private:
    string genKey;
    Map* map;
    BottomMenu* bottomMenu;
    PathFinder* pathFinder;

    vector<Enemy*> enemies;
    int* coins;
    int* score;
    int* level;
    float* enemiesDelay;
    int* enemiesCount;
    int* enemiesSpeed;
    bool fail;
    bool complete;
    vector<Tower*> towers;

    void checkBuildTower();
    void damageEnemy(Enemy*);
    void addEnemy();

public:

    bool levelComplete();
    bool levelFailed();
    int getScore();
    void update(float);
    void draw();
    void create(string);
    Level(int, int, int);
    ~Level();
};