#include "ush.h"

static int get_start_index(char *str) {
    int i = 0;

    while(str[i]) {
        if (str[i] != ' ') {
            return i;
        }
        i++;
    }
    return i;
}

static int get_end_index(char *str) {
    int i = mx_strlen(str) - 1;

    while(i >= 0) {
        if (str[i] != ' ') {
            return i + 1;
        }
        i--;
    }
    return i + 1;
}

t_list *mx_make_tokens(char *str, t_info *processes) {
    int start   = get_start_index(str);
    int end     = get_end_index(str);
    t_token *newToken = 0;
    t_list *tokens = 0;

    mx_is_param_new(str, &start, end, processes);
    while ((newToken = mx_take_next_token(&start, end, str, processes))) {
        if (newToken->type == 2)
            free(newToken);
        else
            mx_push_back(&tokens, newToken);
        if (!(processes->if_ctrl_c))
            return tokens;
    }
    return tokens;
}

t_list *mx_take_info(char *str, t_info *processes) {
    t_list *tokens = 0;

    if (str == 0)
        return 0;
    tokens = mx_make_tokens(str, processes);
    return tokens;
}
