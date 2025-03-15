#include "header.h"

void mx_printstr(char *str) {
    write(1, str, mx_strlen(str));
}
