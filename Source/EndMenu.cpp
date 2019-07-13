#include "../Headers/EndMenu.hpp"

EndMenu::EndMenu()
{
    exitBtn = new Button();

    exitBtn->create("exitbutton");

    exitBtn->setPosition(Vector2f(384, 410));
    exitBtn->setActiveColor(Color::Cyan);
    exitBtn->setAnimScale(1.2f);

    gameOver = new Text();
    scoreInfo = new Text();
    font = new Font();

    *font = Cache::getInstance()->getFont("font1");

    scoreInfo->setFont(*font);
    scoreInfo->setCharacterSize(50);
    scoreInfo->setFillColor(Color::Magenta);
    scoreInfo->setOutlineThickness(5);
    scoreInfo->setOutlineColor(Color::Black);
    scoreInfo->setPosition(Vector2f(250, 300));

    gameOver->setFont(*font);
    gameOver->setCharacterSize(50);
    gameOver->setFillColor(Color::Magenta);
    gameOver->setOutlineThickness(5);
    gameOver->setOutlineColor(Color::Black);
    gameOver->setPosition(Vector2f(210, 200));

    gameOver->setString("Game over!");
}

void EndMenu::update()
{
    exitBtn->update();
    if (exitBtn->isActive()) Cache::getInstance()->window->close();
}

void EndMenu::setScoreInfo(int score)
{
    scoreInfo->setString("Score: " + to_string(score));
}

void EndMenu::draw()
{
    exitBtn->draw();

    Cache::getInstance()->window->draw(*scoreInfo);
    Cache::getInstance()->window->draw(*gameOver);
}

EndMenu::~EndMenu()
{
    delete font;
    delete gameOver;
    delete scoreInfo;
    delete exitBtn;
}