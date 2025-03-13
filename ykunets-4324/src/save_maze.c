#include "../inc/header.h"

void save_maze(char maze[100][100], const char *filename) {
    int file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file < 0) {
        mx_printerr("Error opening file");
        return;
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
       write(file, &maze[i][j], 1);
        }
        write(file, "\n", 1);
    }
    close(file);
}
