#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }
    int len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    char *result_str = (char *)malloc((len + 1) * sizeof(char));
    if (result_str == NULL) {
        return NULL;
    }
    int result_index = 0;
    int i = 0;

    while (i < len) {
        int match = 1;
        for (int j = 0; j < sub_len; j++) {
            if (str[i + j] != sub[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            for (int j = 0; j < replace_len; j++) {
                result_str[result_index] = replace[j];
                result_index++;
            }
            i += sub_len;
        } else {
            result_str[result_index] = str[i];
            result_index++;
            i++;
        }
    }

    result_str[result_index] = '\0';
    return result_str;
}
