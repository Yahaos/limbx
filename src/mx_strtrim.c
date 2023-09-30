#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    int length = mx_strlen(str);
    int start = 0;

    while (start < length && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n' || str[start] == '\r')) {
        start++;
    }

    int end = length - 1;

    while (end >= 0 && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n' || str[end] == '\r')) {
        end--;
    }

    int trim_length = end - start + 1;
    if (trim_length <= 0) {
        return mx_strdup("");
    }
    char *trim_str = (char *)malloc(trim_length + 1);
    if (trim_str == NULL) {
        return NULL;
    }
    mx_strncpy(trim_str, str + start, trim_length);
    trim_str[trim_length] = '\0';

    return trim_str;
}

