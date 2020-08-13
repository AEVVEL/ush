#include "ush.h"

void mx_print_escape(char *s) {
    char temp = 27;

    write(1, &temp, 1);
    write(1, "[", 1);
    mx_printstr(s);
}
