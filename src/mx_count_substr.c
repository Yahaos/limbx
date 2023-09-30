#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1; 
    }
    if (sub[0] == '\0') {
        return 0;
    }
    int cout = 0;
    const char *ptr = str;

    while ((ptr = mx_strstr(ptr, sub)) != NULL) {
        cout++;
        ptr++;
    }

    return cout;
}
