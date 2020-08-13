#include "ush.h"

int mx_ush_get_rank(char *path) {
    int i = -1;
    int rank = 0;

    while(path[++i]) {
        if ((path[i] == '/') && (path[i + 1])) {
            rank++;
        }
    }
    return rank;
}
