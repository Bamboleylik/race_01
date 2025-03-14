#include "../inc/header.h"

bool mx_is_valid(Maze *maze, int x, int y)
{
    // Перевіряємо вихід за межі лабіринту
    if (x < 0 || x >= maze->height || y < 0 || y >= maze->width)
    {
        return false;
    }

    // Перевіряємо, чи клітинка не є стіною
    if (maze->maze[x][y] == '#')
    {
        return false;
    }

    // Перевіряємо, чи клітинка ще не відвідана
    if (maze->visited[x][y] != 0)
    {
        return false;
    }

    return true;
}
