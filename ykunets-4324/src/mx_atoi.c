#include "../inc/header.h"
bool mx_isspace(char c){
    return (c == ' '|| c == '\n' || c == '\t' ||
    c =='\v' || c == '\f' || c == '\r');
}

bool mx_isdigit(int c){
if (c >= 0 && c <= 9){
  return 1;
}
else {
    return 0;
}
}

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

