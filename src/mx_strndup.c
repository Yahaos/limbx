#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL) {
        return NULL;
    }

    size_t len = 0;
    while (s1[len] != '\0' && len < n) {
        len++;
    }

    char *duplicate = (char *)malloc(len + 1);
    if (duplicate == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < len; i++) {
        duplicate[i] = s1[i];
    }
    duplicate[len] = '\0';

    return duplicate;
}
