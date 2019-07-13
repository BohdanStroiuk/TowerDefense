#include "../Headers/Menu.hpp"

Menu::Menu()
{
    startBtn = new Button();
    exitBtn = new Button();

    startBtn->create("startbutton");
    exitBtn->create("exitbutton");

    startBtn->setPosition(Vector2f(384, 300));
    startBtn->setActiveColor(Color::Cyan);
    startBtn->setAnimScale(1.2f);

    exitBtn->setPosition(Vector2f(384, 370));
    exitBtn->setActiveColor(Color::Cyan);
    exitBtn->setAnimScale(1.2f);

    active = true;
}

void Menu::update(float delta)
{
    startBtn->update();
    exitBtn->update();

    if (startBtn->isActive()) active = false;
    if (exitBtn->isActive()) Cache::getInstance()->window->close();
}

bool Menu::isActive()
{
    return active;
}

void Menu::draw()
{
    Sprite sprite;
    Texture texture;

    texture = Cache::getInstance()->getTexture("background");
    sprite.setScale(Vector2f(1, 1.07));
    sprite.setTexture(texture);

    Cache::getInstance()->window->draw(sprite);
    startBtn->draw();
    exitBtn->draw();
}
Menu::~Menu()
{
    delete startBtn;
    delete exitBtn;
}