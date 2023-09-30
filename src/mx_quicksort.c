#include "libmx.h"

int mx_partition(char** arr, int left, int right) {
    int i = left, j = right;
    int sws = 0;
    int pilow = mx_strlen(arr[(left + right) / 2]);

    while (i <= j) {
        while (mx_strlen(arr[i]) < pilow)
            i++;
        while (mx_strlen(arr[j]) > pilow)
            j--;

        if (i <= j) {
            char* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            sws++;
            i++;
            j--;
        }
    }

    return sws;
}

int mx_quicksort(char** arr, int left, int right) {
    if (arr == NULL)
        return -1;

    int sws = 0;

    if (left < right) {
        int pilow_index = mx_partition(arr, left, right);
        sws += mx_quicksort(arr, left, pilow_index);
        sws += mx_quicksort(arr, pilow_index + 1, right);
    }

    return sws;
}
