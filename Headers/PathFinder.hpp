#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

class PathFinder
{

private:
    int** map;
    int* width;
    int* height;

    Vector2i* roadBegin;
    Vector2i* roadEnd;

    vector<Vector2i*> path;

    void buildPath();

    void search(int, int, int);

public:
    vector<Vector2i*> getPath();
    void findPath();
    void loadData(int**, int, int);

    PathFinder();
    ~PathFinder();
};