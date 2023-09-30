#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (lineptr == NULL || buf_size == 0 || fd < 0) {
        return -2;
    }
    char *line = NULL;
    size_t line_size = 0;
    ssize_t bytes_read = 0;
    int delim_found = 0;

    while (1) {
        if (line_size == 0) {
            line = (char *)malloc(buf_size);
            if (line == NULL) {
                return -2;
            }
        }
        bytes_read = read(fd, line + line_size, buf_size - line_size);
        if (bytes_read == -1) {
            free(line);
            return -2;
        } else if (bytes_read == 0) {
            free(line);
            return (delim_found || line_size > 0) ? (int)line_size : -1;
        }
        line_size += (size_t)bytes_read;
        size_t start_pos = line_size - (size_t)bytes_read;

        for (size_t i = start_pos; i < line_size; i++) {
            if (line[i] == delim) {
                delim_found = 1;
                line_size = i;
                break;
            }
        }

        if (delim_found) {
            break;
        }
        if (bytes_read < (ssize_t)buf_size) {
            break; 
        }
    }

    char *result_line = (char *)malloc(line_size + 1);
    if (result_line == NULL) {
        free(line);
        return -2;
    }
    mx_memcpy(result_line, line, line_size);
    result_line[line_size] = '\0';

    free(line);

    *lineptr = result_line;

    return (int)line_size;
}
