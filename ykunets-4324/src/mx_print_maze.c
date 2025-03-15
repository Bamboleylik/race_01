#include "../inc/header.h"
void mx_print_maze(Maze *maze) {
    if (!maze || !maze->maze) return; 

    for (int i = 0; i < maze->height; i++) {
        write(1, maze->maze[i], maze->width);
        write(1, "\n", 1); 
    }
}
