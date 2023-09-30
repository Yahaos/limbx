#include "libmx.h"

void *mx_memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen) {
    if (needlelen > haystacklen) {
        return NULL;
    }

    const unsigned char *hay = (const unsigned char *)haystack;
    const unsigned char *nee = (const unsigned char *)needle;

    for (size_t i = 0; i <= haystacklen - needlelen; i++) {
        if (mx_memcmp(hay + i, nee, needlelen) == 0) {
            return (void *)(hay + i);
        }
    }

    return NULL;
}
