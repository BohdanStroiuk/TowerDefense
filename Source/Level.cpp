#include "../Headers/Level.hpp"

Level::Level(int level, int enemiesCount, int startCoins)
{
    map = new Map();
    bottomMenu = new BottomMenu();
    pathFinder = new PathFinder();

    coins = new int(startCoins);
    score = new int(0);
    enemiesDelay = new float(8);
    enemiesSpeed = new int(15);

    this->enemiesCount = new int (enemiesCount);
    this->level = new int (level);

    fail = false;
    complete = false;

}
void Level::addEnemy()
{
    if (enemies.size() < *enemiesCount)
    {
        enemies.emplace_back(new Enemy());
        enemies.back()->setSpeed(*enemiesSpeed);
        enemies.back()->create("enemy1");
        enemies.back()->loadPath(pathFinder->getPath());

        if (*enemiesSpeed < 20) *enemiesSpeed+= 1;
    }
   
}

void Level::create(string genKey)
{
    this->genKey = genKey;

    map->loadTemplate(Cache::getInstance()->getMap(genKey));

    pathFinder->loadData(map->getTemplate(), map->getHeight(), map->getWidth());

    pathFinder->findPath();

}

void Level::damageEnemy(Enemy* enemy)
{
    for (int j = 0; j < towers.size(); j++)
        if (towers[j]->inAttackZone(enemy->getBound()))
        {
            enemy->damage(towers[j]->getPower(), towers[j]->getPosition());

            if  (!enemy->isAlive()) 
            {
                *coins+=3;
                *score+=5;
            }
        }
        else
        {
            enemy->stopDamage();
        }
            
}
void Level::checkBuildTower()
{
    if (bottomMenu->isSelectTower() && Mouse::isButtonPressed(Mouse::Left))
    {
        string towerType = bottomMenu->getSelectTowerType();
        int price = 0;

        if (towerType == "tower1") price = 1;
        else
            if (towerType == "tower2") price = 3;
            else
                price = 5;

        if (price > *coins)
        {
            bottomMenu->reSelectTower();
        }
        else
        {
            Vector2i clickPosition = Mouse::getPosition(*Cache::getInstance()->window);
        
            int i = clickPosition.y / 32;
            int j = clickPosition.x / 32;

            if (map->getTileCode(i,j) == 2) 
            { 
                map->setTileCode(i,j, 0);

                Tower* tower = new Tower();
                tower->create(towerType);


                tower->setPosition(Vector2f(j*32, i*32));

                towers.emplace_back(tower);
                *coins -= price;
                bottomMenu->reSelectTower();
            }
        }
        
        

    }
}

void Level::draw()
{
    bottomMenu->draw();
    Sprite sprite;
    Texture texture;
    int x, y;

    for (int i = 0; i < map->getHeight(); i++)
    {
        for (int j = 0; j < map->getWidth(); j++)
            {
                if (map->getTileCode(i, j) == 4) 
                {
                    x = j*32;
                    y = i*32 - 32;
                } 
                else
                {
                    texture = Cache::getInstance()->getTexture(map->getTileType(map->getTileCode(i, j)));
                    sprite.setTexture(texture);
                    sprite.setPosition(j*32, i*32);
                    Cache::getInstance()->window->draw(sprite);

                }

            }
    }

    texture = Cache::getInstance()->getTexture(map->getTileType(4));
    sprite.setTexture(texture);

    sprite.setTextureRect(IntRect(0,0,64,64));
    sprite.setPosition(x, y);

     Cache::getInstance()->window->draw(sprite);

    for (int i = 0; i < towers.size(); i++)
    {
        towers[i]->draw();
    }

    for (int i = 0; i < enemies.size(); i++)
        if (enemies[i]->isAlive()) enemies[i]->draw();

    
    
  
}

void Level::update(float delta)
{
    bottomMenu->setCoinsInfo(*coins);
    bottomMenu->setScoreInfo(*score);
    bottomMenu->setLevelInfo(*level);

    bottomMenu->update();

    *enemiesDelay += delta;

    if (*enemiesDelay >= 10) 
    {
        *enemiesDelay = 0;
        addEnemy();
    }

    int count = 0;
    for (int i = 0; i < enemies.size(); i++)
    {
        
        if (enemies[i]->isAlive())
        {
            damageEnemy(enemies[i]);
            enemies[i]->update(delta);

            if (enemies[i]->finished()) fail = true;
        }
        else
        {
            count++;
        }
        
    }

    if (count == *enemiesCount) complete = true;
    
    checkBuildTower();

    for (int i = 0; i < towers.size(); i++)
    {
        towers[i]->update(delta);
    }   
}
int Level::getScore()
{
    return *score;
}

bool Level::levelComplete()
{
    return complete;
}

bool Level::levelFailed()
{
    return fail;
}

Level::~Level()
{
    delete pathFinder;
    
    delete map;
    delete bottomMenu;
    delete level;
    delete coins;
    delete score;
    delete enemiesCount;
    delete enemiesDelay;
    delete enemiesSpeed;

    for (int i = 0; i < enemies.size(); i++)
      delete enemies[i];

    for (int i = 0; i < towers.size(); i++)
        delete towers[i];

}