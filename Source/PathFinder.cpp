#include "../Headers/PathFinder.hpp"
#include <fstream>
#include <iterator>

PathFinder::PathFinder()
{
    roadBegin = new Vector2i(0,0);
    roadEnd = new Vector2i(0,0);
}

void PathFinder::loadData(int** tmp, int height, int width)
{
    this->width = new int(width);
    this->height = new int (height);

    map = new int*[height];

    for (int i = 0; i < height; i++)
    {
        map[i] = new int[width];

        for (int j = 0; j < width; j++)
        {
            map[i][j] = tmp[i][j];

            if ((tmp[i][j] == 0) || (tmp[i][j] == 2) || (tmp[i][j] == 5) || (tmp[i][j] == 6) || (tmp[i][j] == 7))
            {
                map[i][j] = -1;
            }
            else
            {
                if (tmp[i][j] == 3) 
                {
                    roadBegin->x = j;
                    roadBegin->y = i;
                }
                else
                {
                    if (tmp[i][j] == 4) 
                    {
                        roadEnd->x = j;
                        roadEnd->y = i;
                    }
                }
                map[i][j] = 0; 
            }
                   
        }
    }
}

void PathFinder::findPath()
{
    search(1, roadBegin->y, roadBegin->x);
    buildPath();
}

void PathFinder::buildPath()
{
    Vector2i end;
    end.x = roadEnd->y;
    end.y = roadEnd->x;

    path.emplace_back(new Vector2i(end.y, end.x));

    while (map[end.x][end.y] > 1)
    {
        if (((map[end.x][end.y + 1] ) == (map[end.x][end.y] - 1))){ end.y++;} else
		if (((map[end.x][end.y - 1] ) == (map[end.x][end.y] - 1))){ end.y--;} else
		if (((map[end.x - 1][end.y] ) == (map[end.x][end.y] - 1))){ end.x--; } else
		if (((map[end.x + 1][end.y] ) == (map[end.x][end.y] - 1))){ end.x++; }

        path.emplace_back(new Vector2i(end.y, end.x));
    }
/*
    

    for (it = path.begin(); it != path.end(); ++it)
    {
        cout << (*it)->y << " " << (*it)->x << endl;
    }
*/
}

vector<Vector2i*> PathFinder::getPath()
{
    return path;
}

void PathFinder::search(int step, int i, int j)
{
    map[i][j] = step;
    

    if ((j+1) < *width)
        if ((map[i][j+1] != -1) && ((map[i][j+1] >= (step+1)) || (map[i][j+1] == 0))) search(step+1, i, j+1);

    if ((j-1) > -1)
        if ((map[i][j-1] != -1) && ((map[i][j-1] >= (step+1)) || (map[i][j-1] == 0))) search(step+1, i, j-1);

    if ((i+1) < *height)
        if ((map[i+1][j] != -1) && ((map[i+1][j] >= (step+1)) || (map[i+1][j] == 0))) search(step+1, i+1, j);

    if ((i-1) > -1)
        if ((map[i-1][j] != -1) && ((map[i-1][j] >= (step+1)) || (map[i-1][j] == 0))) search(step+1, i-1, j);

}

PathFinder::~PathFinder()
{
    for (int i = 0; i < *height; i++)
         delete map[i];

    delete [] map;

    delete roadBegin;
    delete roadEnd;
    delete width;
    delete height;
}