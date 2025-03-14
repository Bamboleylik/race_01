#include "../inc/header.h"
char *mx_strnew(const int size)

{

    char *c = (char *)malloc(size + 1);
    if (size < 0)
    {
        return NULL;
    }

    if (c == NULL)
    {
        return NULL;
    }

    for (int i = 0; i <= size; i++)
    {
        c[i] = '\0';
    }
    c[size] = '\0';
    return c;
}
