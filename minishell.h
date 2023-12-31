/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:56:32 by shikim            #+#    #+#             */
/*   Updated: 2023/10/30 21:44:46 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*sig mode*/
# define PARENT 0
# define CHILD 1

/*true and false*/
# define FALSE 0
# define TRUE 1
# define ERROR -1

/*check quote in split*/
# define DONE 2

/*token type*/
# define HEREDOC 3
# define REDIR_IN 4
# define REDIR_OUT 5
# define APPEND 6
# define PIPE 7
# define D_QUOTE 8
# define S_QUOTE 9
# define WORD 10

/*node type*/
# define SIMPLE_COMMAND 11
# define COMMAND 12

/*order*/
# define FIRST 99
# define MIDDLE 100
# define LAST 101

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_token
{
	char			*token;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_token_pack
{
	char					*s;
	int						start;
	int						end;
	int						prev_quote_type;
	t_token					*head;
}	t_token_pack;

typedef struct s_split
{
	struct s_token	*head;
	int				status;
}	t_split;

typedef struct s_env_list
{
	char				**envp_copy;
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

typedef struct s_execute
{
	int						n_of_process;
	int						s_n_of_process;
	int						pipe_fd[2];
	int						count;
	int						tmp;
	t_env_list				*env_list;
}	t_execute;

typedef struct s_linked_list
{
	int						fd;
	struct s_linked_list	*next;
}	t_linked_list;

int	g_exit_code;

/*parse*/
t_token			*parse_input(char *input, t_env_list *env_list);
t_token			*parse_origin_input(char *input);
void			check_type(t_token *head);
void			substitution(t_token *head, t_env_list *env_list);
int				check_syntax(t_token *head);
void			unquote(t_token *head);
int				is_operator(char *s);
int				is_operator2(t_token *list);
int				is_operator3(t_token *list);
int				compare_str(char *str1, char *str2);
void			free_env_list(t_env_list *env_list);

/*fixing parsing*/
int				pre_check_quote(char *input);
void			free_token_list(t_token *list);
void			make_quoted_string(t_token *head, char *s, int *st, int e);
void			check_quote(t_token_pack *t_pack);
char			*make_substitute(char *token, t_env_list *env_list);

/*split*/
int				is_sep(char c);
int				check_quote1(char c);
int				check_quote2(char c);
void			trim_word(char **arr);
void			free_list(t_token *head);
void			make_redir_in(t_token *head, char *s, int st);
void			make_redir_out(t_token *head, char *s, int st);
void			insert_string_node(t_token *head, char *s, int *st, int e);
t_token			*split(char *s);
t_token			*insert_node(t_token *head, char *s);
t_token			*create_token(char *s);

/*init_minishell*/
void			init_minishell(int argc, char **argv);

/*read_input*/
char			*read_input(void);

/*sig_handler*/
void			set_signal(void);
void			term_handler(void);
void			int_handler(int sig);

/*term*/
void			set_terminal(void);

/*utils*/
void			set_pid(int	*pid);
void			exit_program(char *s);
void			error_cmd_not_found(char *string);
void			error_cmd_no_file_dir(char *string);

/*env*/
char			*get_env(t_env_list *env_list, char *str);
t_env_list		*set_env(char **envp);
void			free_envp(char **envp_copy);
char			**env_list_to_envp(t_env_list *env_list, int count);

/*exec*/
void			execute(t_token *token_list, t_env_list **env_list, \
						t_token *origin_list);
void			execute_command(t_token *list, t_execute *pack, \
									t_env_list *env_list);
t_token			*move_list(int count, t_token *list);
void			execute_first_command(t_token *list, t_execute *pack, \
										t_env_list *env_list);
void			execute_middle_command(t_token *list, t_execute *pack, \
										t_env_list *env_list);
void			execute_last_command(t_token *list, t_execute *pack, \
										t_env_list *env_list);
int				do_redirin(t_token *list);
int				do_redirout(t_token *list);
t_token			*find_command(t_token *list);
void			execute_word(t_token *list, t_execute *pack, \
								t_env_list *env_list);
int				is_pipe(t_token *list);
void			remove_heredoc_file(void);
char			*make_cmd(t_token *list, t_execute *pack);
char			**make_heredoc_option(void);
void			heredoc_process(t_token *origin_list, t_token *token_list);
char			*find_last_heredoc_name(void);
int				is_exit(t_token *list);
t_linked_list	*insert_l_node(t_linked_list *head, int data);
void			ctrl_exit_status_with_singal(int status);
int				custom_wxd(int status);
int				custom_wss(int status);
int				custom_wgd(int status);
int				custom_wsg(int status);
void			free_l_list(t_linked_list *pid_list);
int				count_pipe(t_token *token_list);
void			check_file_exist(char *file);
t_execute		*init_execute(t_token *token_list, t_env_list *env_list);
t_execute		*init_and_process(t_token *token_list, t_env_list *env_list, \
								t_token *origin_list);

/*builtin*/
int				is_builtin(t_token *token_list);
int				execute_builtin(t_token *token_list, t_env_list **env_list);
void			ft_echo(t_token *token_list);
void			ft_cd(t_env_list *env_list, t_token *token_list);
void			ft_pwd(t_token *bulilt_in_node, t_env_list *env_list);
void			ft_export(t_env_list *env_list, \
							t_token *token_list);
void			add_update_env_list(t_env_list *env_list, \
									char *key, char *value);
t_env_list		*sorted_list(t_env_list *list);
int				compare_keys(t_env_list *a, t_env_list *b);
int				ft_strcmp(char *s1, char *s2);
t_env_list		*create_new_node(t_env_list *list);
t_env_list		*sort_env_list(t_env_list *env_list);
void			ft_unset(t_env_list **env_list, t_token *token_list);
void			ft_env(t_env_list *env_list);
void			ft_exit(t_token *token_list);
void			ctrl_after_equal(t_env_list *env_list, t_token *token_list);
void			error_export(void);
void			enroll_key_with_novalue(t_token *t_list, t_env_list *env_list);
void			enroll_only_key(t_token *t_list, t_env_list *env_list);
void			export_process(t_env_list *env_list, t_token *t_list);
void			set_oldpwd(t_env_list *env_list);

#endif