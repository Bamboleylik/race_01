#include "../inc/header.h"
void mx_free_maze(Maze *maze)
{
    if (!maze)
        return; 

   
    for (int i = 0; i < maze->height; i++)
    {
        free(maze->maze[i]);
    }

    
    free(maze->maze);

    
    free(maze);
}
