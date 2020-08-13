#include "ush.h"

void mx_finish_proceses(t_info *info) {
    t_list *tmp = info->processes;

    while (tmp) {
        if (kill(((t_process*)tmp->data)->pid, SIGKILL) == 0)
            printf("Process closed\n");
        tmp = tmp->next;
    }
}
