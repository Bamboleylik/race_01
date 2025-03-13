#include "../inc/header.h"


int main() {
    FILE *file = fopen("maze.csv", "r");  
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    Maze *maze = mx_read_maze(file);  
    fclose(file);  

    if (maze) {
        print_maze(maze); 
    }

    mx_free_maze(maze);
    

    return 0;
}