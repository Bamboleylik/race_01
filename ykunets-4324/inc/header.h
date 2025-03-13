#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

// Структура для представлення координат
typedef struct {
    int x, y;
} Point;


typedef struct {
    char **maze;        // Двовимірний масив лабіринту
    int width;          // Ширина лабіринту
    int height;         // Висота лабіринту
    Point start;        // Початкова точка
    Point end;          // Кінцева точка
    Point farthest;     // Найвіддаленіша точка
    int **visited;      // Масив для відвіданих точок
} Maze;


void mx_printerr(const char *s);
int mx_strlen(const char *s);
int mx_atoi(const char *str);

Maze *mx_read_maze(const char *filename);      
void mx_free_maze(Maze *maze);                 
int BFS_path(Maze *maze);         
void mx_save_path(Maze *maze, const char *filename);  

void save_maze(char maze[100][100], const char *filename);
bool mx_is_valid(Maze *maze, int x, int y); 
void mx_print_maze(Maze *maze);                   
                   
#endif
