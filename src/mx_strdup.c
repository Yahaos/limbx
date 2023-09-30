#include "libmx.h"

char* mx_strdup(const char* str) {
    const char* vrem = str;
    int size = 0;

    while (*vrem++) {
        size++;
    }

    if (size < 0) {
        return NULL;
    }
    char* dst = (char*)malloc(size + 1);

    for (int i = 0; i <= size; i++) {
        dst[i] = '\0';
    }

    char* ptr = dst;

    for (int i = 0; (dst[i] = str[i]) != '\0'; i++);

    return ptr;
}
