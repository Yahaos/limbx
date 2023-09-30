#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL; 
    }
    int len = 0;
    bool in_word = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !in_word) {
            in_word = true;
            len++;
        } else if (str[i] == ' ' && in_word) {
            in_word = false;
            len++;
        }
    }

    char *result_str = (char *)malloc(len + 1);
    if (result_str == NULL) {
        return NULL; 
    }
    int j = 0;
    in_word = false;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            result_str[j] = str[i];
            j++;
            in_word = true;
        } else if (in_word) {
            result_str[j] = ' ';
            j++;
            in_word = false;
        }
    }

    result_str[len] = '\0'; 
    return result_str;
}
