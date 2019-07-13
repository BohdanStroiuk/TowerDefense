#pragma once
#include "../Headers/Cache.hpp"


class Button
{
private: 
    string key;

    Color* activeColor;
    Texture* texture;
    Sprite* sprite;
    float* animScale;
    
    bool clicked;

    bool checkContact();

public: 
    void setPosition(Vector2f);
    void setActiveColor(Color);
    void setAnimScale(float);
    void reactive();
    

    bool isActive();
    void create(string);
    void update();
    void draw();

    Button();
    ~Button();
};