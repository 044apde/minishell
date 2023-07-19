/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:55:55 by shikim            #+#    #+#             */
/*   Updated: 2023/07/19 20:10:21 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define TRUE 1
# define FALSE 0

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

// parse
void	parse_input(char *input);

// split
char	**split(char *s);
void	trim_word(char **arr);
t_token	*insert_node(t_token *head, char *s);
t_token	*create_token(char *s);
void	make_redir_in(t_token *head, char *s, int st);
void	make_redir_out(t_token *head, char *s, int st);
void	show_token(t_token *head);

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
void	exit_program(void);

#endif