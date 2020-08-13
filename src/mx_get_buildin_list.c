#include "ush.h"

static void buildin_list_1(t_token *token, t_info *info) {
    if (mx_strcmp(token->value[0], "cd") == 0) 
        info->last_status = mx_ush_cd(token->value, info);
    else if (mx_strcmp(token->value[0], "pwd") == 0) 
        info->last_status = mx_ush_pwd(token->value, info);
    else if (mx_strcmp(token->value[0], "echo") == 0) 
        mx_ush_echo(token->value, info);
    else if (mx_strcmp(token->value[0], "exit") == 0)
        mx_ush_exit(token, info);
    else if (mx_strcmp(token->value[0], "fg") == 0)
        mx_ush_fg(token->value, info);
}

static void buildin_list_2(t_token *token, t_info *info) {
    if (mx_strcmp(token->value[0], "export") == 0)
        mx_ush_export(token->value, &(info->var_tree), info);
    else if (mx_strcmp(token->value[0], "unset") == 0)
        mx_ush_unset(token->value, &(info->var_tree), info);
    else if (mx_strcmp(token->value[0], "stop") == 0)
        mx_finish_proceses(info);
    else if (mx_strcmp(token->value[0], "env") == 0)
        mx_ush_env(token->value, info);
    else if (mx_strcmp(token->value[0], "which") == 0)
        mx_ush_which(token->value, info);
    else if (mx_strcmp(token->value[0], "jobs") == 0)
        mx_ush_jobs(info);
}

int mx_get_buildin_list(t_token *token, t_info *info) {
    buildin_list_1(token, info);
    buildin_list_2(token, info);
    return info->exit_status;
}
