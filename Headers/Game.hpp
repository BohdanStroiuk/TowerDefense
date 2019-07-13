#pragma once
#include "../Headers/Level.hpp"
#include "../Headers/Menu.hpp"
#include "../Headers/EndMenu.hpp"

#include <SFML/Graphics.hpp>

class Game
{
private:
    
    
    Menu* menu;
    EndMenu* endMenu;
    int* currentLevel;
    int* score;
    bool end;
    vector<Level*> levels;
    
    RenderWindow* window;

    void update(float);


    static Game* game;
    Game(Game const&);
    Game& operator = (Game const&);
    Game();
    ~Game();
    
public:
    void start();
    static void destroy();
    static Game* getInstance();

    
};