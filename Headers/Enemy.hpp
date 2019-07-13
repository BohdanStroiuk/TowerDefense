#pragma once
#include "../Headers/Cache.hpp"
#include <vector>


class Enemy
{
private:
    

    Texture* texture;
    Sprite* sprite;
    Vector2f* position;
    bool damaged;
    
    

    float* speed;
    float* hp;
    RectangleShape* hpBound;
    RectangleShape* hpLine;

    vector<Vector2i*> path;
    int* nextTile;

    bool alive;
    void move(float);
    bool fin;
    

public:
    Vector2f getPosition();
    FloatRect getBound();
    bool finished();
    bool isAlive();
    void damage(int, Vector2f);
    void stopDamage();
    void create(string);
    void loadPath(vector<Vector2i*>);
    void setSpeed(float);
    void update(float);
    void draw();
    Enemy();
    ~Enemy();

};