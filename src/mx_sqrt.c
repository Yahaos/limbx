#include "libmx.h"

int mx_sqrt(int x) {
    if (x >= 1) {
        int k = 1;

        while (x > k * k) {
            k++;
        }

        if (k * k == x) {
            return k;
        }
    }
    return 0;
}
