#include "../inc/header.h"

bool mx_isspace(char c) {
    if (c == 32 || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r') {
        return true;
    }
    else {
        return false;
    }
}
