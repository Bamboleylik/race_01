#include "header.h"

void remove_commas(char *str)
{
    char *dest = str;
    for (char *src = str; *src != '\0'; src++)
    {
        if (*src != ',')
        {
            *dest++ = *src;
        }
    }
    *dest = '\0';
}

Maze *mx_read_maze(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error opening file\n", 19);
        exit(1);
    }

    Maze *maze = malloc(sizeof(Maze));
    if (!maze)
    {
        write(2, "Memory allocation failed\n", 25);
        close(fd);
        exit(1);
    }

    maze->height = 0;
    maze->width = 0;
    maze->maze = NULL;

    char buffer[1024];
    char *line = buffer;
    int bytes_read, i = 0, line_start = 0;

    while ((bytes_read = read(fd, buffer + i, 1)) > 0)
    {
        if (buffer[i] == '\n' || buffer[i] == '\0')
        {
            buffer[i] = '\0';
            remove_commas(line);

            int length = i - line_start;
            if (length > maze->width)
                maze->width = length;

            maze->height++;
            maze->maze = realloc(maze->maze, maze->height * sizeof(char *));
            maze->maze[maze->height - 1] = malloc((length + 1) * sizeof(char));

            int j;
            for (j = 0; j < length; j++)
            {
                maze->maze[maze->height - 1][j] = line[j];
            }
            maze->maze[maze->height - 1][j] = '\0';

            line_start = i + 1;
        }
        i++;
    }

    close(fd);
    return maze;
}
