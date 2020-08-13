#ifndef MACROSES_H
#define MACROSES_H

// #include <sys/cdefs.h>
// #include <sys/_types.h>
// #include <sys/_types/_pid_t.h>
// #include <sys/_types/_id_t.h>
// #include <sys/signal.h>
// #include <sys/resource.h>

#define MX_W_INT(w)         (*(int *)&(w))
#define MX_WST(x)           (x & 0177)
#define MX_WIFEXIT(x)       (MX_WST(x) == 0)
#define MX_WIFSIG(x)        (MX_WST(x) != _WSTOPPED && MX_WST(x) != 0)
#define MX_WTERMSIG(x)      (MX_WST(x))
#define MX_EXSTATUS(x)      ((MX_W_INT(x) >> 8) & 0x000000ff)

#define MX_STR info->input->comands[info->input->id]
#define MX_COMMAND info->input->comands
#define MX_ID info->input->id
#define MX_STR_LEN info->input->str_len
#define MX_STR_POS info->input->end_posit
#define MX_MAX_COMAND info->input->max_comand
#define MX_SYMBOL info->input->if_
#define MX_ID_TAB_KEY info->input->pos_tab
#define MX_FLAGS_W O_RDWR | O_CREAT | O_TRUNC, S_IWRITE | S_IREAD
#define MX_FLAGS_WE O_RDWR | O_CREAT | O_APPEND, S_IWRITE | S_IREAD
#define MAX_PROC_COUNT 500
#define mx_ush_history_STRING "u$h> "
#define MX_NAME "\x4u$h> "
#define MX_SEARCH "\x8Search > "
#define MX_PATH ((t_token *)tmp->next->next->data)->value[0]
#define MX_FUNC_RETURN mx_get_value("HOME", &(info->var_tree))
#define MX_GET_PATH (argv[i] ? argv[i] : MX_FUNC_RETURN)
#define MX_AMPERSAND "\033[1;31m\'&\' - not allowed in this version!\033[0m\n"
#define MX_DLES "\033[1;31m\'<<\' - not allowed in this version!\033[0m\n"
#define MX_REG_EXPORT "^[A-Za-z_]+[A-Za-z_0-9]*(=.*)?$"
#define MX_REG_ERR "^^-(i+)?[^Pui]"
#define MX_REG_I "^-i+((P|u)?|((P|u).+)?)$"
#define MX_REG_U "^-(i+)?u.*$"
#define MX_REG_P "^-(i+)?P.*$"
#define MX_REG_VER "^.+=.*$"
#define MX_REG_PROG "^[^-]"

#endif
