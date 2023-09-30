#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -2;
    }
    const char *found = mx_strstr(str, sub);
    if (found != NULL) {
        return found - str; 
    } else {
        return -1; 
    }
}
