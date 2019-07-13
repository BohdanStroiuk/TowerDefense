#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iterator>

using namespace sf;
using namespace std;


class Cache
{

private:
    const string texturesFile = "textures.txt";
    const string levelsFile = "maps.txt";
    const string fontsFile = "fonts.txt";

    const int windowWidth = 768;
    const int windowHeight = 512;
    Texture t;
    
    map<string, Texture*> textures;
    map<string, pair<int**, pair<int*, int*>>> maps;
    map<string, Font*> fonts;

    static Cache* cache;
    Cache(Cache const&);
    Cache& operator = (Cache const&);

    void loadCache();

    void loadTextures();
    void loadMaps();
    void loadFonts();

    pair<int**, pair<int*, int*>> readMap(string);

    Cache();
    ~Cache();
    
public:
    RenderWindow*  window;

    Font getFont(string);
    Texture getTexture(string);
    pair<int**, pair<int*, int*>> getMap(string);
    static Cache* getInstance();
    static void destroy();
    
};