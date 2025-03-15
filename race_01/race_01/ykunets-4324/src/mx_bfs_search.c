#include "../inc/header.h"

void mx_bfs_search(Maze *maze, Point start) {
    int dx[] = {0, 0, -1, 1};  
    int dy[] = {-1, 1, 0, 0};
    
    
    maze->visited = malloc(maze->height * sizeof(int *));
    for (int i = 0; i < maze->height; i++) {
        maze->visited[i] = malloc(maze->width * sizeof(int));
        for (int j = 0; j < maze->width; j++) {
            maze->visited[i][j] = 0;  
        }
    }

    
    Point *queue = malloc(maze->height * maze->width * sizeof(Point));
    int front = 0, rear = 0;
    queue[rear++] = start; 
    maze->visited[start.x][start.y] = 1;

    maze->farthest = start;

    while (front < rear) {
        Point current = queue[front++];

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            
            if (mx_is_valid(maze, nx, ny)) {
                maze->visited[nx][ny] = maze->visited[current.x][current.y] + 1;
                queue[rear++] = (Point){nx, ny};

                if (maze->visited[nx][ny] > maze->visited[maze->farthest.x][maze->farthest.y]) {
                    maze->farthest = (Point){nx, ny};
                }
            }
        }
    }

    free(queue);  
}
