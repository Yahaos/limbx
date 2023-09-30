#include "libmx.h"

int mx_count_words(const char* str, char c) {
    int d = 0, f = 0;

    while (*str) {
        if (*str == c || *str == '\n'){
            d = 0;
        }
        else if (d == 0) {
            d = 1;
            f++;
        }
        str++;
    }

    return f;
}
