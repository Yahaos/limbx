#include "libmx.h"

void mx_del_strarr(char ***arr) {
    char **c = *arr;

    while (*c){
        free(c++);
    }

    mx_strdel(*arr);
}
