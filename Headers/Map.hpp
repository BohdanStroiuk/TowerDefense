#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

using namespace std;
using namespace sf;

class Map
{
private:
    map<int, string> tileCodes;

    int* height;
    int* width;
    int** mapTemplate;

public:
    void loadTemplate(pair< int**, pair<int*, int*>>);

    int** getTemplate();

    void setTileCode(int, int, int);
    int getTileCode(int, int);
    string getTileType(int);
    int getWidth();
    int getHeight();
    
    Map();
    ~Map();
};