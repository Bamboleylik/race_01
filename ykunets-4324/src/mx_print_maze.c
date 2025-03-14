#include "header.h"

void mx_print_maze(Maze *maze) {
    if (!maze || !maze->maze) {
        return; 
    }

    for (int i = 0; i < maze->height; i++) {
        mx_printstr(maze->maze[i]);
        mx_printchar('\n'); 
    }
}
