#include "../Headers/Tower.hpp"

Tower::Tower()
{
    frameNum = new int(0);
    sprite = new Sprite();
    texture = new Texture();
    expl = new Texture();
    explo = new Sprite();

    *expl = Cache::getInstance()->getTexture("expl");
    explo->setTexture(*expl);

    attackZone = new RectangleShape();

    attackZone->setSize(Vector2f(64, 64));
    
    attackZone->setOutlineThickness(2);
    attackZone->setOutlineColor(Color::Black);
    attackZone->setFillColor(Color::Transparent);

 
    
    setFrame();
    power = new float(0);
    delta = 0;
   
}

void Tower::setFrame()
{
    
    explo->setTextureRect(IntRect(Vector2i(*frameNum*96, 0), Vector2i(96, 96)));

}
bool Tower::inAttackZone(FloatRect object)
{
    if (attackZone->getGlobalBounds().intersects(object)) 
    {
        return true;
    }

    return false;
}

void Tower::create(string type)
{
    *texture = Cache::getInstance()->getTexture(type);
    sprite->setTexture(*texture);
    if (type == "tower1") *power = 1;
    else
        if (type == "tower2") *power = 2;
        else
            *power = 3;
        
}

int Tower::getPower()
{
    return *power;
}
void Tower::setPosition(Vector2f position)
{
    sprite->setPosition(position);
    attackZone->setPosition(position.x-16, position.y-16);
    explo->setPosition(position.x-32, position.y-32);
}

void Tower::update(float dt)
{
    this->delta += dt;

    if (delta > 1)
    {
        delta = 0;

        *frameNum += 1;

        if (*frameNum > 2) *frameNum = 0;
       
    }
    setFrame();
    
}

void Tower::draw()
{
    Cache::getInstance()->window->draw(*explo);
//    Cache::getInstance()->window->draw(*attackZone);
    Cache::getInstance()->window->draw(*sprite);
}

Vector2f Tower::getPosition()
{
    return sprite->getPosition();
}

Tower::~Tower()
{
    delete sprite;
    delete texture;
    delete attackZone;
    delete power;
    delete expl;
    delete frameNum;
    delete explo;
}