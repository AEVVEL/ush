#include "ush.h"

void mx_check_new_line_need(void) {
    int twidth = mx_take_term_width() - 1;
    int save_fd1 = dup(1);
    int term_fd1 = open("/dev/tty", O_WRONLY);

    dup2(term_fd1, 1);
    write(1,"%",1);
    for (int i = 0; i < twidth; i++)
        write(1," ",1);
    write(1,"\r",1);
    mx_print_escape("J");
    dup2(save_fd1, 1);
    close(save_fd1);
    close(term_fd1);
}

static void print_two_str(char *str1, char *str2) {
    mx_printstr(str1);
    mx_printstr(str2);
}

void mx_monit_free_new(char *name, int table2, int pos, char *str) {
    int symbol = mx_symbol_bit(&str[table2 - pos - 1]);
    int len = (int) name[0];
    int col = mx_take_term_width();

    print_two_str(&name[1], str);
    mx_printstr(" ");
    for (int i = (mx_symbol_len(table2, str) + len) / col; i > 0; i--)
        mx_print_escape("1F");
    write(1,"\r",1);
    mx_printstr(&name[1]);
    write(1, str, table2 - pos - 1);
    if ((mx_symbol_len(table2 - pos, str) + len) % col == 0) {
        if (pos == 0)
            write(1, " ", 1);
        else
            write(1, &str[table2 - pos - 1], symbol);
        write(1, "\b", 1);
    }
    mx_printstr("\x1b[0m");
}

void mx_monit_clear_new(char *name, int table2, int pos, char *str) {

    int temp;
    int len = (int)name[0];

    temp = (mx_symbol_len(table2 - pos, str) + len) / mx_take_term_width();
    for (int i = temp; i > 0; i--) {
        mx_print_escape("1F");
    }
    write(1,"\r",1);
    mx_print_escape("J");
}

void mx_monit_clear(char *str, t_info *info, char *new_str) {
    int temp;
    int col = mx_take_term_width();

    temp = (mx_symbol_len(MX_STR_LEN - MX_STR_POS, str) + 4) / col;
    for (int i = temp; i > 0; i--) {
        mx_print_escape("1F");
    }
    write(1,"\r",1);
    mx_print_escape("J");
    mx_printstr(mx_ush_history_STRING);
    mx_printstr(new_str);
    mx_printstr(" \x1b[0m\n");
}
