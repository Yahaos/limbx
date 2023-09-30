#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int cout = 0;

    while(*s1) {
	    cout++;
	    s1++;
	}

	while(*s2) {
	    cout++;
		*s1++ = *s2++;
	}

	*s1 = '\0';
	return s1 - cout;
}
