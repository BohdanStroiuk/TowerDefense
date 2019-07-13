#pragma once
#include "../Headers/Cache.hpp"
#include "../Headers/Button.hpp"

class EndMenu
{
private:
    Button* exitBtn;

    Font* font;
    Text* gameOver;
    Text* scoreInfo;

public:
    void setScoreInfo(int);
    void draw();
    void update();

    EndMenu();
    ~EndMenu();
};