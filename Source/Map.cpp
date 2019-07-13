#include "../Headers/Map.hpp"

Map::Map()
{
    tileCodes.emplace(0, "grass");
    tileCodes.emplace(1, "road");
    tileCodes.emplace(2, "ground");
    tileCodes.emplace(3, "enemyspawn");
    tileCodes.emplace(4, "enemyfinish");
    tileCodes.emplace(5, "tree");
    tileCodes.emplace(6, "rock");
    tileCodes.emplace(7, "stump");

    
}

void Map::loadTemplate(pair<int** ,pair<int*, int*>> tmp)
{
    width = new int (*tmp.second.first);
    height = new int(*tmp.second.second);
    
    mapTemplate = new int*[*height];


    for (int i = 0; i < *height; i++)
        mapTemplate[i] = new int[*width];

    for (int i = 0; i < *height; i++)
    {
        for (int j = 0; j < *width; j++)
        {
            mapTemplate[i][j] = tmp.first[i][j];

        }  
    }
}


int Map::getTileCode(int i, int j)
{
    if ((i > -1) && (i < *height) && (j > -1) && (j < *width))
    {
        return mapTemplate[i][j];
    }
    
    return -5;
}

void Map::setTileCode(int i, int j, int code)
{
    if ((i > -1) && (i < *height) && (j > -1) && (j < *width))
    {
        mapTemplate[i][j] = code;
    }
}

int Map::getHeight()
{
    return *height;
}

int Map::getWidth()
{
    return *width;
}

string Map::getTileType(int code)
{
    return tileCodes.at(code);
}

int** Map::getTemplate()
{
    return mapTemplate;
}

Map::~Map()
{
    for (int i = 0; i < *height; i++)
         delete mapTemplate[i];

    delete [] mapTemplate;

    delete width;
    delete height;
   
}