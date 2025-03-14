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


void mx_printerr(const char *msg);
int mx_strlen(const char *s);
int mx_atoi(const char *str);
bool mx_isspace(char c);
bool mx_isdigit(int c);
char *mx_strcpy(char *dst, const char *src);
char *mx_strnew(const int size);
char *mx_strdup(const char *str);


Maze *mx_read_maze(const char *filename);      
void mx_free_maze(Maze *maze);                 
void mx_bfs_search(Maze *maze, Point start);    
void mx_save_path(Maze *maze, const char *filename); 


bool mx_is_valid(Maze *maze, int x, int y); 
void mx_print_maze(Maze *maze);                   
                   
#endif
