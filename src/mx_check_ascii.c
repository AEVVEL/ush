#include "ush.h"

static int ctrl_enter_d_c(t_info *info) {
    if (MX_SYMBOL == -1) {
        mx_monit_clear(MX_STR, info, "exit");
        return 0;
    }
    else if (MX_SYMBOL == 2) {
        mx_monit_clear_new(MX_NAME, MX_STR_LEN, MX_STR_POS, MX_STR);
        return 2;
    }
    else if (MX_SYMBOL == KEY_ENTER) {
        mx_monit_clear(MX_STR, info, MX_STR);
        if (mx_strlen(MX_STR) != 0) {
            if (info->history == NULL
                || mx_strcmp(MX_STR, info->history->data) != 0)
                mx_push_front(&info->history, mx_strdup(MX_STR));
            return 1;
        }
    }
    return 3;
}

int mx_check_ascii(t_info *info, char *chars, unsigned int ch) {
    int spec_symbol = 3;

    if (ch < 32) {
        mx_extra_symb(ch, info);
        if (MX_SYMBOL == -1 || MX_SYMBOL == 2 || MX_SYMBOL == 13)
            spec_symbol = ctrl_enter_d_c(info);
        else
            chars[2] = 10;
    }
    else {
        mx_monit_clear_new(MX_NAME, MX_STR_LEN, MX_STR_POS, MX_STR);
        mx_ush_symb_one(&(MX_STR), ch, &(MX_STR_LEN), MX_STR_POS);
    }
    return spec_symbol;
}
