#include "header.h"

char *mx_strdup(const char *str) {
    char *copy = mx_strnew(mx_strlen(str));

    if (str == NULL) {
        return NULL;
    }

    mx_strcpy(copy, str);

    return copy;
}
