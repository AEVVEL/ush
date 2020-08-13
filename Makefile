NAME = ush

SRCD = src
INCD = inc
OBJD = obj
LBMXD = libmx

LMBX = libmx.a
INC = ush.h
SRC = mx_add_env.c \
	mx_arr1_add_to_arr2.c \
	mx_cd_flag_l.c \
	mx_cd_flag_p.c \
	mx_characteristic_shell.c \
	mx_check_ascii.c \
	mx_check_buildin.c \
	mx_check_char.c \
	mx_check_command.c \
	mx_check_double.c \
	mx_check_link.c \
	mx_check_operator.c \
	mx_check_pipe.c \
	mx_check_str.c \
	mx_check_tokens.c \
	mx_clear_tree_node.c \
	mx_cont_out.c \
	mx_corect_end_of_flag.c \
	mx_create_tree.c \
	mx_del_no_child.c \
	mx_del_param.c \
	mx_delete_last_process.c \
	mx_delete_process_by_pid.c \
	mx_dell_back_rank.c \
	mx_dell_tnode.c \
	mx_dell_tokens.c \
	mx_dell_tree.c \
	mx_dell_var_for_env.c \
	mx_echo_espections.c \
	mx_entry_prog.c \
	mx_env_out.c\
	mx_error_for_env.c \
	mx_exec.c \
	mx_extra_symbol.c\
	mx_fill_tree.c \
	mx_find_list.c \
	mx_finish_proceses.c \
	mx_flang_comand.c \
	mx_free_path_for_env.c \
	mx_generat_comands.c \
	mx_get_buildin_list.c \
	mx_get_env_proceses.c \
	mx_get_path_for_env.c \
	mx_get_token.c \
	mx_get_value.c \
	mx_handle_events.c \
	mx_input.c \
	mx_input_status.c \
	mx_insert_tree.c \
	mx_is_param_new.c \
	mx_is_symbol_in_position.c \
	mx_last_status_param.c \
	mx_len_strarr.c \
	mx_make_arg_to_proc.c \
	mx_make_token.c \
	mx_make_token_in_prog.c \
	mx_make_vars_for_env.c \
	mx_monit_clear.c\
	mx_new_tree_node.c \
	mx_not_ascii.c \
	mx_param_2x_tab.c \
	mx_param_ush_end.c \
	mx_pars_tab.c \
	mx_pipes.c\
	mx_print_comand_with_tab.c \
	mx_print_error_for_env.c \
	mx_print_escape.c \
	mx_replace.c \
	mx_segfault_error.c \
	mx_select_tree_node.c \
	mx_shell_param.c \
	mx_signal_r.c \
	mx_signal_v_and_non_ascii.c \
	mx_sleeped_process.c \
	mx_start.c \
	mx_start_prog_tree.c \
	mx_str_bquote.c \
	mx_subs.c \
	mx_susp_out.c \
	mx_symbol_len.c \
	mx_tab_param.c \
	mx_take_info.c \
	mx_take_inform.c \
	mx_take_min_tree_node.c \
	mx_take_name.c \
	mx_take_next_token.c \
	mx_take_term_width.c \
	mx_take_type_token.c \
	mx_ush_add_proc.c \
	mx_ush_add_rank.c \
	mx_ush_begin_proces.c \
	mx_ush_cd.c \
	mx_ush_clear_fd.c \
	mx_ush_close.c \
	mx_ush_echo.c \
	mx_ush_env.c \
	mx_ush_env_exec_dop.c \
	mx_ush_exe_more.c \
	mx_ush_exit.c \
	mx_ush_export.c \
	mx_ush_export_for_env.c \
	mx_ush_fg.c \
	mx_ush_get_new_pwd.c \
	mx_ush_get_rank.c \
	mx_ush_home.c \
	mx_ush_is_not_operator.c \
	mx_ush_jobs.c \
	mx_ush_parser.c \
	mx_ush_parser_input.c \
	mx_ush_pwd.c \
	mx_ush_reading_comand.c \
	mx_ush_regular.c \
	mx_ush_start.c \
	mx_ush_symb_one.c \
	mx_ush_unset.c \
	mx_ush_which.c \
    mx_ush_main.c \


INCLUDE = -I $(LBMXD) \
	-I $(INCD) \

LBMXS = $(addprefix $(LBMXD)/, $(LMBX))
INCS = $(addprefix $(INCD)/, $(INC))
SRCS = $(addprefix $(SRCD)/, $(SRC))
OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))
	
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror

CC = clang

all: $(NAME)

install: $(NAME) clean

$(LBMXS):
	@make -sC $(LBMXD)

$(NAME): $(OBJS) $(LBMXS)
	@$(CC) -ltermcap $(CFLAGS) $(LBMXS) $(OBJS) -o $@

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

uninstall: clean
	@make -sC $(LBMXD) $@
	@rm -rf $(NAME)

clean:
	@make -sC $(LBMXD) $@
	@rm -rf $(OBJD)

reinstall: uninstall install