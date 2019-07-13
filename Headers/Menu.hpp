#pragma once
#include "../Headers/Cache.hpp"
#include "../Headers/Button.hpp"

class Menu
{
private:
    Button* startBtn;
    Button* exitBtn;

    bool active;
    
public:
    bool isActive();
    void draw();
    void update(float);
    Menu();
    ~Menu();
};