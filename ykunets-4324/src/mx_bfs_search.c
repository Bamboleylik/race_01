#include "header.h"

void mx_bfs_search(Maze *maze, Point start) {
    int dx[] = {-1, 1, 0, 0}; 
    int dy[] = {0, 0, -1, 1};

    if (maze == NULL || maze->height == 0 || maze->width == 0) {
        mx_printerr("map does not exist\n");
        return;
    }
    
    maze->visited = malloc(maze->height * sizeof(int *));

    if (maze->visited == NULL) {
        mx_printerr("error\n");
        return;
    }

    for (int i = 0; i < maze->height; i++) {
        maze->visited[i] = calloc(maze->width, sizeof(int));
    }

    Point queue[maze->height * maze->width];
    int front = 0;
    int rear = 0;
    queue[rear++] = start; 
    maze->visited[start.x][start.y] = 1; 
    maze->farthest = start; 

    while (front < rear) {
        Point current = queue[front++]; 

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // Якщо точка доступна
            if (mx_is_valid(maze, nx, ny)) {
                maze->visited[nx][ny] = maze->visited[current.x][current.y] + 1; 
                queue[rear++] = (Point){nx, ny};

                if (maze->visited[nx][ny] > maze->visited[maze->farthest.x][maze->farthest.y]) {
                    maze->farthest = (Point){nx, ny};
                }
            }
        }
    }
}
