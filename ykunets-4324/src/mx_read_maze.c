#include "header.h"

void remove_commas(char *str) {
    char *dest = str;

    for (char *src = str; *src != '\0'; src++) {
        if (*src != ',' && !mx_isspace(*src)) {
            *dest++ = *src;
        }
    }

    *dest = '\0';
}

Maze *mx_read_maze(const char *filename) {
    int fd = open(filename, O_RDONLY);

    if (fd < 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    Maze *maze = malloc(sizeof(Maze));

    if (!maze) {
        mx_printerr("error\n");
        close(fd);
        exit(1);
    }

    maze->height = 0;
    maze->width = 0;
    maze->maze = NULL;
    char buffer[1024];
    int i = 0;
    int line_start = 0;

    while (read(fd, buffer + i, 1) > 0) {
        if (buffer[i] == '\n' || buffer[i] == '\0') {
            buffer[i] = '\0';
            char *current_line = buffer + line_start;

            remove_commas(current_line); 

            int length = mx_strlen(current_line);

            if (length > maze->width) {
                maze->width = length;
            }

            maze->height++;
            maze->maze = realloc(maze->maze, maze->height * sizeof(char *));
            maze->maze[maze->height - 1] = mx_strdup(current_line);
            line_start = i + 1;
        }

        i++;
    }

    // Обробка останнього рядка (якщо файл не закінчується \n)
    if (i > line_start) {
        buffer[i] = '\0';
        char *current_line = buffer + line_start;

        remove_commas(current_line);

        int length = strlen(current_line);

        if (length > maze->width) {
            maze->width = length;
        }

        maze->height++;
        
        maze->maze = realloc(maze->maze, maze->height * sizeof(char *));
        maze->maze[maze->height - 1] = mx_strdup(current_line);
    }

    close(fd);
    return maze;
}
