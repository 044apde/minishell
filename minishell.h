
#ifndef MINISHELL_H
# define MINISHELL_H

# define FALSE 0
# define TRUE 1
# define DONE 2

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include "libft/libft.h"

typedef struct s_token
{
	char			*token;
	int				type;
	struct s_token	*next;
}	t_token;

typedef struct s_split
{
	struct s_token	*head;
	int				status;
}	t_split;

typedef struct s_env_list
{
	char				*key;
	char				*value;
	struct s_env_list	*next;
}	t_env_list;

// parse
void	parse_input(char *input);

// split
int		is_sep(char c);
int		check_quote1(char c);
int		check_quote2(char c);
int		check_quote(char c);
void	trim_word(char **arr);
void	free_list(t_token *head);
void	show_token(t_token *head);
void	make_redir_in(t_token *head, char *s, int st);
void	make_redir_out(t_token *head, char *s, int st);
void	insert_string_node(t_token *head, char *s, int *st, int e);
t_token	*split(char *s);
t_token	*insert_node(t_token *head, char *s);
t_token	*create_token(char *s);

// init_minishell
void	init_minishell(int *pid);

// read_input
char	*read_input(int pid);

// sig_handler
void	set_signal(int *pid);
void	term_handler(void);

// term
void	set_terminal(void);

// utils
void	set_pid(int	*pid);
void	exit_program(char *s);

#endif