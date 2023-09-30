#include "libmx.h"

void *mx_memmove(void *dest, const void *src, size_t n) {
    unsigned char *d = dest;
    const unsigned char *s = src;
    if (d == s) {
        return dest;
    }
    if (d < s || d >= s + n) {
        while (n--) {
            *d++ = *s++;
        }
    } else {
        unsigned char temp[n];
        for (size_t i = 0; i < n; i++) {
            temp[i] = s[i];
        }
        for (size_t i = 0; i < n; i++) {
            d[i] = temp[i];
        }
    }

    return dest;
}
