#pragma once
#include "../Headers/Cache.hpp"

class Tower
{
private:
    int* frameNum;
    Texture* expl;
    Sprite* explo;

    Texture* texture;
    Sprite* sprite;

    float delta;

    RectangleShape* attackZone;
    
    float* power;
    void setFrame();

public:
    Vector2f getPosition();
    int getPower();
    void update(float);
    void create(string);
    void setPosition(Vector2f);
    bool inAttackZone(FloatRect);
    void draw();
    Tower();
    ~Tower();
};