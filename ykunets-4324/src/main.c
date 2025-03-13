#include "../inc/header.h"

int main() {
    // FILE *file = fopen("maze.csv", "r");  
    // if (!file) {
    //     perror("Failed to open file");
    //     return 1;
    // }

    // Maze *maze = mx_read_maze(file);  
    // fclose(file);  
    char map[100][100] = {
        {'#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', '#', '#', '#', '#'}
    };

    save_maze(map, "maze.txt");

    return 0;
}
