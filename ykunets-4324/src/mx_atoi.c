#include "../inc/header.h"

int mx_atoi(const char *src) {
    int i = 0;
    int sign = 1;
    long long result = 0;
    if (src == 0){
        return 0;
    }
    while (mx_isspace(src[i])) {
        i++;
    }
    if (src[i] == '-' || src[i] == '+') {
        if (src[i] == '-') {
            sign = -1;
        }
       i++;
    }
    while (mx_isdigit(src[i])) {
       result = result * 10 + (src[i] - '0');
       i++;
    }

    return (int)result * sign;
}

