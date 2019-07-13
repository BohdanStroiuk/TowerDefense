#include "../Headers/Button.hpp"

Button::Button()
{
    texture = new Texture();
    sprite = new Sprite();
    animScale = new float(1);

    activeColor = new Color();
    *activeColor = Color::White; 

   clicked = false;
}

void Button::setAnimScale(float newScale)
{
    *animScale = newScale;
}

void Button::reactive()
{
    clicked = false;
}
void Button::create(string key)
{
    *texture = Cache::getInstance()->getTexture(key);
    sprite->setTexture(*texture);

    sprite->setOrigin(Vector2f(sprite->getLocalBounds().width/2, sprite->getLocalBounds().height/2));
}

bool Button::isActive()
{
    return clicked;
}

void Button::update()
{
    if (!clicked && checkContact() && Mouse::isButtonPressed(Mouse::Left))
    {
        clicked = true;
        sprite->setColor(Color::Yellow);
        sprite->setScale(Vector2f(0.95, 0.95));
    } 
}


bool Button::checkContact()
{
    Vector2f cursorPosition = Vector2f(Mouse::getPosition(*Cache::getInstance()->window).x, Mouse::getPosition(*Cache::getInstance()->window).y);

    if (sprite->getGlobalBounds().contains(cursorPosition))
    {
        sprite->setColor(*activeColor);
        sprite->setScale(Vector2f(*animScale, *animScale));

        return true;
    }
        if (!clicked)
        {
            sprite->setColor(Color::White);
            sprite->setScale(Vector2f(1,1));
        }
        
        return false;
}

void Button::draw()
{
    Cache::getInstance()->window->draw(*sprite);
}
void Button::setActiveColor(Color color)
{
    *activeColor = color;
}

void Button::setPosition(Vector2f newPosition)
{
    sprite->setPosition(newPosition);
}
Button::~Button()
{
    delete sprite;
    delete texture;
    delete activeColor;
    delete animScale;
    
}