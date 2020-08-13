#include "ush.h"
#include "macroses.h"

static void check_status(char **argv, int status, t_info *info, pid_t pr) {
    char **mas_name = 0;

    if (MX_WIFSIG(status)) {
        if (MX_WTERMSIG(status) == SIGSEGV)
            mx_segfault_error();
        if (MX_WTERMSIG(status) == SIGINT) {
            mx_delete_process_by_pid(info, pr);
            info->last_status = 130;
        }
    }
    else {
        mx_ush_add_proc(&(info->processes), pr, argv);
        mas_name = mx_take_name(info, pr);
        mx_susp_out(mas_name);
    }
}

void mx_sleeped_process(t_info *info, char **argv) {
    int status = 0;
    pid_t pr = 0;

    pr = waitpid(-1, &status, WUNTRACED); 
    if (!MX_WIFEXIT(status)) {
        check_status(argv, status, info, pr);
    }
    else {
        mx_delete_process_by_pid(info, pr);
        info->last_status = MX_EXSTATUS(status);
    }
}
