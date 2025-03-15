#include "header.h"

void mx_save_path(Maze *maze, const char *filename) {
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0) {
        mx_printerr("error\n");
        return;
    }

    char **path = malloc(maze->height * sizeof(char *));

    if (!path) {
        mx_printerr("error\n");
        close(fd);
        exit(1);
    }

    for (int i = 0; i < maze->height; i++){
        path[i] = mx_strdup(maze->maze[i]);
    }
    
    Point current = maze->end;

    while (current.x != maze->start.x || current.y != maze->start.y) {
        path[current.x][current.y] = '*';
        int min_dist = maze->visited[current.x][current.y];
        Point next = current;

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx >= 0 && nx < maze->height && ny >= 0 && ny < maze->width) {
                if (maze->visited[nx][ny] < min_dist && maze->visited[nx][ny] > 0) {
                    min_dist = maze->visited[nx][ny];
                    next = (Point){nx, ny};
                }
            }
        }

        current = next;
    }

    path[maze->start.x][maze->start.y] = '*';
    int max_dist = 0;

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->visited[i][j] > max_dist) {
                max_dist = maze->visited[i][j];
            }
        }
    }

    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->visited[i][j] == max_dist && path[i][j] != '*') {
                path[i][j] = 'D';
            }
        }
    }

    if (maze->visited[maze->end.x][maze->end.y] == max_dist) {
        path[maze->end.x][maze->end.y] = 'X';
    }

    for (int i = 0; i < maze->height; i++) {
        write(fd, path[i], maze->width);
        write(fd, "\n", 1);
    }

    close(fd);

    for (int i = 0; i < maze->height; i++) {
        free(path[i]);
    }
    
    free(path);
}
