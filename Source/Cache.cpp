#include "../Headers/Cache.hpp"


Cache* Cache::cache = 0;

Cache::Cache()
{
    loadCache();
}

void Cache::loadCache()
{
    loadTextures();
    loadMaps();
    loadFonts();
}

void Cache::loadFonts()
{
     ifstream file(fontsFile);

    while(!file.eof())
    {
        string type;
        string fileName;

        file >> type >> fileName;
        
        fonts.emplace(type, new Font());

        fonts.at(type)->loadFromFile(fileName);

    }

    file.close();
}

void Cache::loadMaps()
{
    ifstream file(levelsFile);

    while(!file.eof())
    {
        string type;
        string fileName;

        file >> type >> fileName;
        

        maps.emplace(type, readMap(fileName));
    }

    file.close();
}

pair<int**, pair<int*, int*>> Cache::readMap(string fileName)
{

    ifstream file(fileName);

    int *width = new int(), *height = new int();
    file >> *width >> *height;

    int** map = new int*[*height];


    for (int i = 0; i < *height; i++)
    {
        map[i] = new int[*width];
        for (int j = 0; j < *width; j++)
        {
            file >> map[i][j];
            
        }
       
            
    }
    file.close();

    return make_pair(map, make_pair(width, height));
}

pair<int**, pair<int*, int*>> Cache::getMap(string type)
{
    return make_pair(maps.at(type).first, maps.at(type).second);
}

void Cache::loadTextures()
{
    ifstream file(texturesFile);

    while(!file.eof())
    {
        string type;
        string fileName;

        file >> type >> fileName;
        
        textures.emplace(type, new Texture());

        textures.at(type)->loadFromFile(fileName);
    }

    file.close();
}

Texture Cache::getTexture(string type)
{
   return *textures.at(type);
}

Font Cache::getFont(string type)
{
    return *fonts.at(type);
}


Cache* Cache::getInstance()
{
    if (!cache)
    {
        cache = new Cache();
    }
    return cache;
}


void Cache::destroy()
{
    delete cache;
    cache = NULL;

}

Cache::~Cache()
{
    map<string, Texture*>::iterator it;

    for (it = textures.begin(); it != textures.end(); ++it)
    {
        delete it->second;
    }

    map<string, pair<int**, pair<int*, int*>>>::iterator it1;

    for (it1 = maps.begin(); it1 != maps.end(); ++it1)
    {
        for (int i = 0; i < *it1->second.second.second; i++)
        {
            delete it1->second.first[i];
        }
        delete it1->second.first;

        delete it1->second.second.first;
        delete it1->second.second.second;
    }

    map<string, Font*>::iterator it2;

    for (it2 = fonts.begin(); it2 != fonts.end(); ++it1)
    {
        delete it2->second;
    }
    
}