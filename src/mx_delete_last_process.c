#include "ush.h"

void mx_delete_last_process(t_info *info) {
    if (!info->processes)
        return;
    mx_del_strarr(&((t_process*)info->processes->data)->name);
    mx_pop_front(&info->processes);
}
