#include "../Headers/Enemy.hpp"
#include <iostream>
#include <cmath>

Enemy::Enemy()
{
   
    texture = new Texture();
    sprite = new Sprite();
    position = new Vector2f(0,0);
    speed = new float(0);
    hp = new float(100);
    alive = true;
    hpBound = new RectangleShape();
    hpLine = new RectangleShape();

    hpLine->setSize(Vector2f(32, 10));
    hpBound->setSize(Vector2f(32, 10));

    hpBound->setOutlineThickness(2);
    hpBound->setOutlineColor(Color::Black);

    hpLine->setFillColor(Color::Green);
    hpBound->setFillColor(Color::Red);
    fin = false;
}

void Enemy::setSpeed(float speed)
{
    *this->speed = speed;
}

void Enemy::damage(int dm, Vector2f towerPos)
{
    *hp-=dm;
    hpLine->setSize(Vector2f(*hp*0.32, 10.f));
    

    if (*hp < 0) alive = false;
}

bool Enemy::isAlive()
{
    return alive;
}
void Enemy::loadPath(vector<Vector2i*> newPath)
{
    for (int i = newPath.size()-1; i >= 0; i--)
    {
        path.emplace_back(new Vector2i(*newPath[i]));
    }

    nextTile = new int(1);

    sprite->setPosition(Vector2f(path[0]->x * 32, path[0]->y * 32));
    *position = sprite->getPosition();
    hpLine->setPosition(Vector2f(position->x, position->y -15));
    hpBound->setPosition(Vector2f(position->x, position->y -15));
}

void Enemy::update(float delta)
{
    move(delta);
}

FloatRect Enemy::getBound()
{
    return sprite->getGlobalBounds();
}

void Enemy::stopDamage()
{
    damaged = false;
}

void Enemy::move(float delta)
{

    float distX = path[*nextTile]->x*32 - position->x;
    float distY = path[*nextTile]->y*32 - position->y;

    if (distX < 0 ) distX*=-1;
    
    if (distY < 0 ) distY*=-1;

    if (distX > *speed/4)
    {
//        cout << "MoveX " << delta * (path[*nextTile]->x*32 - position->x)/ distX * *speed << endl;
        position->x += delta * (path[*nextTile]->x*32 - position->x)/ distX * *speed;
        
        
    }
    else
    {
        

        if (distY > *speed/4)
        {
//           cout << "MoveY " << delta * (path[*nextTile]->y*32 - position->y)/ distY * *speed << endl;
            position->y += delta * (path[*nextTile]->y*32 - position->y)/ distY * *speed;
        } 
        else
        {
            position->x = path[*nextTile]->x*32;
            position->y = path[*nextTile]->y*32;
            if (*nextTile != path.size()-1 ) 
                *nextTile += 1;
            else
                fin = true;
        }
        
    }
    
    sprite->setPosition(*position);
    hpLine->setPosition(Vector2f(position->x, position->y -15));
    hpBound->setPosition(Vector2f(position->x, position->y -15));

}
bool Enemy::finished()
{
    return fin;
}

void Enemy::create(string type)
{
    *texture = Cache::getInstance()->getTexture(type);
    sprite->setTexture(*texture);
}

void Enemy::draw()
{
    Cache::getInstance()->window->draw(*sprite);
    
    Cache::getInstance()->window->draw(*hpBound);
    Cache::getInstance()->window->draw(*hpLine);

}

Vector2f Enemy::getPosition()
{
    return *position;
}

Enemy::~Enemy()
{
    delete sprite;
    delete texture;
    delete nextTile;
    delete hpLine;
    delete speed;
    delete position;
    delete hp;
    delete hpBound;
 
  
 //   path.clear();

}