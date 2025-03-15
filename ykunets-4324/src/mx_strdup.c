#include "../inc/header.h"

char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);

char *mx_strdup(const char *str)
{

    char *c = mx_strnew(mx_strlen(str));

    if (c == NULL)
    {
        return NULL;
    }

    mx_strcpy(c, str);

    return c;
}
