#include "libmx.h"

char* mx_nbr_to_hex(unsigned long nbr) {
    int nbrlen = nbr;
    int length = 0, r = 0;

    while (nbr != 0) {
        r = nbr % 16;
        nbr /= 16;
        length++;
    }

    if (length == 0) {
        return 0;
    }
    char* h = mx_strnew(length);

    for (int i = length - 1; i >= 0; i--) {
        r = nbrlen % 16;
        if (r < 10) {
            h[i] = r + 48;
        }
        else {
            h[i] = r + 32 + 55;
        }
        nbrlen /= 16;
    }

    return h;
}
