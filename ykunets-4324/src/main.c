#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        mx_printerr("Usage: ./way_home <filename> <x1> <y1> <x2> <y2>\n");
        exit(1);
    }

    const char *filename = argv[1];
    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    Maze *maze = mx_read_maze(filename);

    if (!maze) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    if (x1 < 0 || y1 < 0 || x1 >= maze->width || y1 >= maze->height 
        || x2 < 0 || y2 < 0 || x2 >= maze->width || y2 >= maze->height) {
        mx_printerr("points are out of map range\n");
        free(maze);
        exit(1);
    }

    if (maze->maze[y1][x1] == '#') {
        mx_printerr("entry point cannot be an obstacle\n");
        free(maze);
        exit(1);
    }

    if (maze->maze[y2][x2] == '#') {
        mx_printerr("exit point cannot be an obstacle\n");
        free(maze);
        exit(1);
    }

    maze->start = (Point){x1, y1};
    maze->end = (Point){x2, y2};

    mx_bfs_search(maze, maze->start);

    if (maze->visited[maze->end.y][maze->end.x] == 0) {
        mx_printerr("route not found\n");
        free(maze);
        exit(1);
    }

    int dist = maze->visited[maze->farthest.x][maze->farthest.y] - 1;
    int exit_dist = maze->visited[maze->end.x][maze->end.y] - 1;

    mx_printstr("dist=");
    mx_printint(dist);
    mx_printchar('\n');
    mx_printstr("exit=");
    mx_printint(exit_dist);
    mx_printchar('\n');
    mx_save_path(maze, "path.txt");

    // Звільнення пам'яті
    for (int i = 0; i < maze->height; i++) {
        free(maze->maze[i]);
    }

    free(maze->maze);

    for (int i = 0; i < maze->height; i++) {
        free(maze->visited[i]);
    }

    free(maze->visited);
    free(maze);

    return 0;
}
