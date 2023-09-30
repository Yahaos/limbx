#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    double che = 1.0;

    for(unsigned int i = 0; i < pow; i++){
        che *= n;
    }

    return che;
}
