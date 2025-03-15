#include "../inc/header.h"

void remove_commas(char *str)
{
    char *dest = str;
    for (; *str; str++)
    {
        if (*str != ',' && !mx_isspace(*str))
            *dest++ = *str;
    }
    *dest = '\0';
}

Maze *mx_read_maze(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        mx_printerr("map does not exist\n");
        exit(1);
    }

    int height = 0, width = 0, curr_width = 0;
    char c;
    while (read(fd, &c, 1) > 0)
    {
        if (c == '\n')
        {
            height++;
            if (curr_width > width)
                width = curr_width;
            curr_width = 0;
        }
        else if (c != ',' && !mx_isspace(c))
        {
            curr_width++;
        }
    }
    if (curr_width > 0)
    {
        height++;
        if (curr_width > width)
            width = curr_width;
    }

    close(fd);
    fd = open(filename, O_RDONLY);
    Maze *maze = malloc(sizeof(Maze));
    if (!maze) {
        mx_printerr("error\n");
        close(fd);
        exit(1);
    }
    maze->height = height;
    maze->width = width;
    maze->maze = malloc(height * sizeof(char *));

    char *line = malloc(width + 1);
    int row = 0, idx = 0;
    while (read(fd, &c, 1) > 0)
    {
        if (c == '\n' || c == '\0')
        {
            line[idx] = '\0';
            remove_commas(line);
            maze->maze[row++] = mx_strdup(line);
            idx = 0;
        }
        else if (c != ',' && !mx_isspace(c))
        {
            line[idx++] = c;
        }
    }
    if (idx > 0)
    {
        line[idx] = '\0';
        remove_commas(line);
        maze->maze[row] = mx_strdup(line);
    }

    free(line);
    close(fd);
    return maze;
}
