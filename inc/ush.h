#ifndef USH_H
#define USH_H

#include "libmx.h"
#include "macroses.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <pwd.h>
#include <regex.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <term.h>
#include <termcap.h>
#include <time.h>
#include <unistd.h>
#include <xlocale.h>

typedef struct s_var {
    char *name;
    char *value;
    bool flag;
    struct s_var *next;
}              t_var;

typedef struct s_variable {
    char *name;
    char *value;
    bool is_env;
    char *mem;
}              t_variable;

typedef struct s_tree_node {
    struct s_tree_node *left;
    struct s_tree_node *right;
    struct s_tree_node *parent;
    void *data;
} t_tnode;

enum e_branch
{
    RIGHT,
    LEFT
};

enum e_operator_status { 
    OP_NOTHING,
    OP_PIPE_R,
    OP_PIPE_W,
    OP_PIPE_RW,
    OP_MORE = 4,
    OP_DMORE = 8,
    OP_LESS = 16,
    LEFT_VISITED = 128,
    RIGHT_VISITED = 64,
    OP_AMP = 32
};

enum e_type_of_token{
    TYPE_OPERATOR,
    TYPE_COMMAND,

    TYPE_FILENAME,
    TYPE_DESC_NUMB,
};

typedef struct s_token{
    char type;
    char **value;
    int priority;
}              t_token;

typedef struct s_process {
    char **name;
    pid_t pid;
    int index;
}              t_process;

typedef struct s_input {
    char **comands;
    char **comand_tab;
    int id;
    int max_comand;
    int str_len;
    int end_posit;
    int if_;
    int pos_tab;
}              t_input;

typedef struct s_programInfo {
    struct termios term_old;
    struct termios term_new;
    char **env;
    t_list *history;
    t_input *input;
    t_list *processes;
    bool is_exit;
    bool if_ctrl_c;
    int exit_status;
    char *pwd;
    char *pwd_l;
    char *pwd_p;
    char *old_pwd;
    char *path;
    char *home;
    t_list *var_tree;
    int last_status;
}              t_info;

enum e_keys{
    CTRL_A = 1,
    CTRL_W = 23,
    CTRL_E = 5,
    CTRL_R = 18,
    CTRL_T = 20,
    CTRL_Y = 25,
    CTRL_U = 21,
    CTRL_I = 9,
    CTRL_P = 16,
    CTRL_CLOSE_BRACKET = 29,
    CTRL_D = 4,
    CTRL_F = 6,
    CTRL_G = 7,
    CTRL_H = 8,
    CTRL_K = 11,
    CTRL_L = 12,
    CTRL_Z = 26,
    CTRL_X = 24,
    CTRL_C = 3,
    CTRL_B = 2,
    CTRL_N = 14,
    KEY_ESCAPE = 27,
    KEY_SPACE = 32,
    KEY_ENTER = 13
};

bool mx_check_buildin(char *str);
bool mx_check_char(char c);
bool mx_check_command(char *fullname, int flags);
bool mx_check_link(char *file);
bool mx_check_operator(t_token *token);
bool mx_check_tokens(t_list *tokens);
bool mx_error_for_env(char **argv, char **path, t_var *var, int *i);
bool mx_is_double_less(t_list *tmp);
bool mx_is_double_more(t_list *tmp);
bool mx_is_double_op(t_list *tmp, bool *op);
bool mx_is_symbol_in_position(char *str, int position, char symbol);
bool mx_print_error_for_env(char *str, int flag);
bool mx_ush_is_not_operator(char c);
bool mx_ush_regular(char *str, char *regular);
char **mx_generat_comands(char *str, int end);
char **mx_make_arg_to_proc(char **argv, int i);
char **mx_make_vars_for_env(t_var *var);
char **mx_tab_param(char *parsing, char **str, t_info *info);
char **mx_take_name(t_info *info, int numb);
char *mx_check_str(char *str, t_info *processes, bool dqute);
char *mx_get_path_for_env(char *str1, char *str2, int *i);
char *mx_get_value(char **str, t_list **var_tree);
char *mx_get_value_new(const char *str, t_list **var_tree);
char *mx_pars_tab(char *parsing, t_info *info);
char *mx_str_bquote(char **str, t_info *processes);
char *mx_ush_get_new_pwd(char *path, t_info *info);
char *mx_ush_parser_input(char *str);
char mx_take_type_token(char *str);
char *mx_dell_back_rank(char *path);
char *mx_ush_add_rank(char *path, char *new_part);
int mx_cd_flag_l(char *path, t_info *info, char flags);
int mx_cd_flag_p(char *path, t_info *info, char flags);
int mx_check_ascii(t_info *info, char *chars, unsigned int ch);
int mx_check_pipe(t_tnode *root, int *fds, char operator_status, t_info *processes);
int mx_corect_end_of_flag(char *str, int *position, int end, int flag);
int mx_dell_var_for_env(char *str1, char *str2, t_var *var, int *i);
int mx_echo_espections(char *str, int *i);
int mx_flang_comand(char *str, int *pos, int end, int flag);
int mx_get_buildin_list(t_token *token, t_info *info);
int mx_get_token(t_token *token, int *fds, char operator_status, t_info *info);
int mx_handle_events(char ch);
int mx_input_status(t_info *info);
int mx_len_strarr(char **str);
int mx_no_pipe(t_tnode *root, char opst, t_info *pr);
int mx_param_ush_end(char *str, int i);
int mx_pipe_r(t_tnode *root, int *fds, char operator_status, t_info *processes);
int mx_start_prog_tree(t_tnode *root, int *fds, char operator_status, t_info *info);
int mx_symbol_bit(char *str);
int mx_symbol_len(int sum, char *str);
int mx_take_term_width();
int mx_ush_add_proc(t_list **processes, pid_t pid, char **name);
int mx_ush_cd(char **argv, t_info *info);
int mx_ush_env_exec_dop(t_tnode *root, int *fds, int operatorStatus, t_info *info);
int mx_ush_exe_more(t_tnode *root, int *fds, int operator_status, t_info *info);
int mx_ush_get_rank(char *path);
int mx_ush_pwd(char **argv, t_info *info);
t_info *mx_take_inform(t_info *info);
t_list *mx_take_info(char *str, t_info *processes);
t_tnode *mx_new_tree_node(void *data);
t_tnode *mx_select_tree_node(t_tnode *root, void *data, int (*cmp)(void *, void *));
t_tnode *mx_create_tree(t_list **tokens, t_tnode *prev);
t_tnode *mx_take_min_tree_node(t_tnode *root);
t_token *mx_make_token(char type, char **value, int priority);
t_token *mx_make_token_in_prog(int *curr_pos, int end, char *str, t_info *processes);
t_token *mx_take_next_token(int *start, int end, char *str, t_info *processes);
t_var *mx_fill_tree(t_list *var_tree);
unsigned int mx_input(t_info *info);
void mx_add_env(t_list **var_tree, char *name, char *value, char *mem);
void mx_arr1_add_to_arr2(char ***strs, char ***str);
void mx_characteristic_shell(t_info *processes, int *i, char **new_str);
void mx_check_new_line_need(void);
void mx_clear_tree_node(t_tnode **root, void *data, int (*cmp)(void *, void *), void (*free_tnode)(t_tnode *tnode));
void mx_clear_tree_node(t_tnode **root, void *data, int (*cmp)(void *, void *), void (*free_tnode)(t_tnode *tnode));
void mx_cont_out(char **mas_name, int pid);
void mx_del_param(t_info *info);
void mx_delete_last_process(t_info *info);
void mx_delete_no_child(t_tnode **root, void *data, int (*cmp)(void *, void *), void (*free_tnode)(t_tnode *tnode));
void mx_delete_process_by_pid(t_info *info, int pid);
void mx_delete_tnode_1ch(t_tnode **root, void *data, int (*cmp)(void *, void *), void (*free_tnode)(t_tnode *tnode));
void mx_delete_tnode_2ch(t_tnode **root, int (*cmp)(void *, void *), t_tnode *finded, void (*free_tnode)(t_tnode *tnode));
void mx_dell_tokens(t_list **tokens);
void mx_dell_tree(t_tnode **root);
void mx_entry_prog(t_list **var_tree, char **env);
void mx_env_out(t_var *var);
void mx_exec(t_tnode *root, int *fds, char operator_status, t_info *info);
void mx_extra_symb(unsigned int ch, t_info *info);
void mx_find_list(t_list **var_tree, char *name, char *value);
void mx_finish_proceses(t_info *info);
void mx_free_path_for_env(t_var *var, char *path);
void mx_get_env_proceses(char *path, char **argv, char **env, t_info *info);
void mx_insert_tree(t_tnode **root, t_tnode *new, int (*cmp)(void *, void *), void (*free_)(void *));
void mx_is_param_new(char *str, int *start, int end, t_info *processes);
void mx_last_status_param(t_info *processes, int *i, char **new_str, int flag);
void mx_monit_clear(char *str, t_info *info, char *new_str);
void mx_monit_clear_new(char *name, int table2, int pos, char *str);
void mx_monit_free_new(char *name, int table2, int pos, char *str);
void mx_not_ascii(char *chars, t_info *info);
void mx_param_2x_tab(char **str, char **comands, t_info *info);
void mx_print_comand_with_tab(t_list *list_comand);
void mx_print_escape(char *s);
void mx_replace(char **str, size_t start, size_t end, char *str_new);
void mx_segfault_error();
void mx_segfault_exit();
void mx_shell_param(t_info *processes, int *i, char **new_str);
void mx_signal_c();
void mx_signal_r(t_info *info);
void mx_signal_v_and_non_ascii(t_info *info, char *chars);
void mx_signal_z();
void mx_sleeped_process(t_info *info, char **argv);
void mx_start(char **commands, t_info *processes);
void mx_subs(char **str);
void mx_susp_out(char **mas_name);
void mx_ush_begin_proces(t_token *token);
void mx_ush_clear_fd(int *fds, int *savedFds, int operator_starus);
void mx_ush_echo(char **str, t_info *info);
void mx_ush_end(t_info *info);
void mx_ush_env(char **argv, t_info *info);
void mx_ush_exit(t_token *token, t_info *info);
void mx_ush_export(char **argv, t_list **var_tree, t_info *info);
void mx_ush_export_for_env(char *value, char *tmp, t_variable *data);
void mx_ush_fg(char **argv, t_info *info);
void mx_ush_home(char **str, int *i, t_info *processes);
void mx_ush_jobs(t_info *info);
void mx_ush_parser(char *str, t_info *info);
void mx_ush_reading_comand(char *parsing, t_list **list_comand);
void mx_ush_start(t_info **info, char **env);
void mx_ush_symb_one(char **str, char ch, int *count, int position);
void mx_ush_unset(char **argv, t_list **var_tree, t_info *info);
void mx_ush_which(char **argv, t_info *info);

#endif
