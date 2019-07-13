#include "../Headers/BottomMenu.hpp"

BottomMenu::BottomMenu()
{
    tower1Btn = new Button();
    tower2Btn = new Button();
    tower3Btn = new Button();

    font = new Font();

    *font = Cache::getInstance()->getFont("font1");

    levelInfo = new Text();
    coinsInfo = new Text();
    scoreInfo = new Text();

    levelInfo->setFont(*font);
    coinsInfo->setFont(*font);
    scoreInfo->setFont(*font);

    levelInfo->setCharacterSize(40);
    coinsInfo->setCharacterSize(25);
    scoreInfo->setCharacterSize(25);

    levelInfo->setFillColor(Color::Yellow);
    coinsInfo->setFillColor(Color::Green);
    scoreInfo->setFillColor(Color::Blue);

    levelInfo->setOutlineThickness(2);
    coinsInfo->setOutlineThickness(2);
    scoreInfo->setOutlineThickness(2);

    levelInfo->setOutlineColor(Color::Black);
    coinsInfo->setOutlineColor(Color::Black);
    scoreInfo->setOutlineColor(Color::Black);


    levelInfo->setPosition(Vector2f(550, 540));
    coinsInfo->setPosition(Vector2f(310, 530));
    scoreInfo->setPosition(Vector2f(310, 570));

 //   levelInfo->setString("Level 1");
 //   coinsInfo->setString("Coins: 2");
  //  scoreInfo->setString("Score: 100");


    tower1Btn->create("tower1Button");
    tower2Btn->create("tower2Button");
    tower3Btn->create("tower3Button");

    tower1Btn->setPosition(Vector2f(50, 566));
    tower2Btn->setPosition(Vector2f(152, 566));
    tower3Btn->setPosition(Vector2f(254, 566));

    tower1Btn->setActiveColor(Color::Green);
    tower2Btn->setActiveColor(Color::Green);
    tower3Btn->setActiveColor(Color::Green);

    tower1Btn->setAnimScale(1.1);
    tower2Btn->setAnimScale(1.1);
    tower3Btn->setAnimScale(1.1);

    buildTowerType = "";
    towerSelected = false;
}

void BottomMenu::setCoinsInfo(int coins)
{
    coinsInfo->setString("Coins: " + to_string(coins));
}

void BottomMenu::setLevelInfo(int level)
{
    levelInfo->setString("Level " + to_string(level));
} 

void BottomMenu::setScoreInfo(int score)
{
   scoreInfo->setString("Score: " + to_string(score));
}
void BottomMenu::update()
{
    tower1Btn->update();
    tower2Btn->update();
    tower3Btn->update();

    if (tower1Btn->isActive())
    {
      
        towerSelected = true;

        buildTowerType = "tower1";

        tower2Btn->reactive();
        tower3Btn->reactive();
    }
    else
    {
        if (tower2Btn->isActive())
        {
            
            towerSelected = true;

            buildTowerType = "tower2";

            tower1Btn->reactive();
            tower3Btn->reactive();
        }
        else
        {
             if (tower3Btn->isActive())
            {
                
                towerSelected = true;
                buildTowerType = "tower3";

                tower1Btn->reactive();
                tower2Btn->reactive();
            }
        }
    }

}
bool BottomMenu::isSelectTower()
{
    return towerSelected;
}

void BottomMenu::reSelectTower()
{
    towerSelected = false;
    buildTowerType = "";

    tower1Btn->reactive();
    tower2Btn->reactive();
    tower3Btn->reactive();
}

string BottomMenu::getSelectTowerType()
{
    return buildTowerType;
}

void BottomMenu::draw()
{
    Sprite sprite;
    Texture texture;

    texture = Cache::getInstance()->getTexture("bottommenu");

    sprite.setTexture(texture);
    sprite.setPosition(Vector2f(0, 513));

    Cache::getInstance()->window->draw(sprite);

    tower1Btn->draw();
    tower2Btn->draw();
    tower3Btn->draw();

    Cache::getInstance()->window->draw(*levelInfo);
    Cache::getInstance()->window->draw(*coinsInfo);
     Cache::getInstance()->window->draw(*scoreInfo);

}

BottomMenu::~BottomMenu()
{
    delete tower1Btn;
    delete tower2Btn;
    delete tower3Btn;
    delete levelInfo;
    delete coinsInfo;
    delete scoreInfo;
  
}