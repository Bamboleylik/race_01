#include "../inc/header.h"

bool mx_is_valid(Maze *maze, int x, int y)
{
   
    if (x < 0 || x >= maze->height || y < 0 || y >= maze->width)
    {
        return false;
    }

   
    if (maze->maze[x][y] == '#')
    {
        return false;
    }

   
    if (maze->visited[x][y] != 0)
    {
        return false;
    }

    return true;
}
