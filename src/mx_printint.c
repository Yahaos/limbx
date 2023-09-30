#include "libmx.h"

void mx_printint(int n) {
    if (n < 0)
    {
        n *= -1;
        mx_printchar('-');
    }
    int t = n, des = 0;

    while (t > 0)
    {
        t /= 10;
        des++;
    }

    char x[des];

    for (int i = des - 1; i >= 0; i--)
    {
        t = n % 10;
        x[i] = t + 48;
        n /= 10;
    }

    for (int j = 0; j < des; j++)
    {
        mx_printchar(x[j]);
    }
}
