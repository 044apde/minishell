#ifndef MINISHELL_H
# define MINISHELL_H

// true and false
# define FALSE 0
# define TRUE 1

// check quote in split
# define DONE 2

// token type
# define HEREDOC 3
# define REDIR_IN 4
# define REDIR_OUT 5
# define APPEND 6
# define PIPE 7
# define DOUBLE_QUOTE 8
# define SIGNLE_QUOTE 9
# define WORD 10

// node type
# define SIMPLE_COMMAND 11
# define COMMAND 12

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				type;
	char			*token;
	struct s_node	*next;
	struct s_node	*left;
	struct s_nope	*right;
}	t_node;

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
void		parse_input(char *input, t_env_list *env_list);
void		check_type(t_token *head);
void		substitution(t_token *head, t_env_list *env_list);
void		check_syntax(t_token *head);
void		unquote(t_token *head);
char		*replace_to_env(char *s, t_env_list *env_list);
int			is_operator(char *s);
int			compare_str(char *str1, char *str2);
t_node		*make_tree(t_token *head);

// split
int			is_sep(char c);
int			check_quote1(char c);
int			check_quote2(char c);
int			check_quote(char c);
void		trim_word(char **arr);
void		free_list(t_token *head);
void		show_token(t_token *head);
void		make_redir_in(t_token *head, char *s, int st);
void		make_redir_out(t_token *head, char *s, int st);
void		insert_string_node(t_token *head, char *s, int *st, int e);
t_token		*split(char *s);
t_token		*insert_node(t_token *head, char *s);
t_token		*create_token(char *s);

// init_minishell
void		init_minishell(int argc, char **argv);

// read_input
char		*read_input(void);

// sig_handler
void		set_signal(void);
void		term_handler(void);

// term
void		set_terminal(void);

// utils
void		set_pid(int	*pid);
void		exit_program(char *s);

// env
char		*get_env(t_env_list *env_list, char *str);
t_env_list	*set_env(char **envp);

#endif