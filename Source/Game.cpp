#include "../Headers/Game.hpp"

Game* Game::game = 0;

Game::Game()
{
    
    menu = new Menu();
    endMenu = new EndMenu();
    currentLevel = new int(0);
    score = new int(0);

    end = false;

}

Game* Game::getInstance()
{
    if (!game)
    {
        game = new Game();
    }
    return game;
}

void Game::start()
{
    window = new RenderWindow(VideoMode(768, 620), "Tower Defense", Style::Default);
    Cache::getInstance()->window = window;

    for (int i = 1; i <= 5; i++)
    {
        levels.emplace_back(new Level(i, i + 2, i+4));
        levels.back()->create("level" + to_string(i));
    }


    Clock clock;
    
    while (Cache::getInstance()->window->isOpen())
    {
        sf::Event event;
        while (Cache::getInstance()->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Cache::getInstance()->window->close();
        }

        Cache::getInstance()->window->clear();
        Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();
        
    
        if (menu->isActive())
        {
            menu->update(dtAsSeconds);
            menu->draw();
        }
        else
        {
            if (end)
            {
                endMenu->update();
                
                levels[*currentLevel]->draw();
                endMenu->draw();

            }
            else
            {
                if (!levels[*currentLevel]->levelFailed()) 
                {
                    levels[*currentLevel]->update(dtAsSeconds);
                    levels[*currentLevel]->draw();

                    if (levels[*currentLevel]->levelComplete()) 
                    {
                        *score += levels[*currentLevel]->getScore();

                        if (*currentLevel == 4)
                        {
                            end = true;
                            endMenu->setScoreInfo(*score);
                        }
                        else
                            *currentLevel+=1;
                    }
                }
                else
                {
                    end = true;
                    endMenu->setScoreInfo(*score);
                }
                
            }
            
        }
        
        Cache::getInstance()->window->display();
    }
}

void Game::destroy()
{
    delete game;
    game = NULL;

}

Game::~Game()
{
    for (int i = 0; i < levels.size(); i++)
        delete levels[i];
    
    delete currentLevel;
    delete score;
    delete menu;
    delete endMenu;


    Cache::getInstance()->destroy();
}