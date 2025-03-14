#include "../inc/header.h"

int main(int argc, char *argv[]) {
    if (argc != 6) {
        write(2, "Usage: ./way_home <filename> <x1> <y1> <x2> <y2>\n", 45);
        exit(1);
    }

    const char *filename = argv[1];
    int x1 = mx_atoi(argv[2]);
    int y1 = mx_atoi(argv[3]);
    int x2 = mx_atoi(argv[4]);
    int y2 = mx_atoi(argv[5]);

    Maze *maze = mx_read_maze(filename);
    maze->start = (Point){x1, y1};
    maze->end = (Point){x2, y2};

    mx_bfs_search(maze, maze->start);

    int dist = maze->visited[maze->farthest.x][maze->farthest.y] - 1;
    int exit_dist = maze->visited[maze->end.x][maze->end.y] - 1;

    printf("dist=%d\n", dist);
    printf("exit=%d\n", exit_dist);

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
