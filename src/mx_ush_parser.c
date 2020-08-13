#include "ush.h"

void mx_ush_parser(char *str, t_info *info) {
    int end = mx_strlen(str);
    char *temp = mx_ush_parser_input(str);
    char **comands = 0;

    if (temp == 0) {
        return;
    }
    if (mx_is_symbol_in_position(str, end -1, '\\')) {
        mx_strdel(&temp);
        mx_printerr("u$h: parse error near | \\ |\n");
        return;
    }
    comands = mx_generat_comands(temp, end);
    mx_start(comands, info);
    mx_del_strarr(&comands);
}
