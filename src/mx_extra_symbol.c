#include "ush.h"

void mx_extra_symb(unsigned int ch, t_info *info) {
    int str_pos = MX_STR_LEN - MX_STR_POS - 1;
    char *str_tab = 0;

    if (MX_SYMBOL != 9 && ch == 9) {
        str_tab = mx_strndup(MX_STR,str_pos);
        mx_monit_clear_new(MX_NAME, MX_STR_LEN, MX_STR_POS, MX_STR);
        info->input->comand_tab = mx_tab_param(str_tab, &MX_STR, info);
        info->input->pos_tab = 0;
    }
    if (MX_SYMBOL == 9 && ch == 9) {
        mx_monit_clear_new(MX_NAME, MX_STR_LEN, MX_STR_POS, MX_STR);
        mx_param_2x_tab(&MX_STR, info->input->comand_tab, info);
    }
    MX_SYMBOL = mx_handle_events(ch);
    if (MX_SYMBOL == 18) {
        mx_monit_clear_new(MX_NAME, MX_STR_LEN, MX_STR_POS, MX_STR);
        mx_signal_r(info);
    }
}
