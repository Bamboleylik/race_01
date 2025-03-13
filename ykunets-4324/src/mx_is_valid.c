#include <header.h>

bool mx_is_valid_move(Maze *maze, int x, int y) {
    // Перевіряємо вихід за межі лабіринту
    if (x < 0 || x >= maze->width || y < 0 || y >= maze->height) {
        return false;
    }

   
    if (maze->maze[y][x] == '#') {
        return false;
    }

  
    if (maze->visited[y][x] == 1) {
        return false;
    }

    return true; 
}