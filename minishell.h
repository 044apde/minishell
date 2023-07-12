/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:55:55 by shikim            #+#    #+#             */
/*   Updated: 2023/07/12 13:29:10 by shikim           ###   ########.fr       */
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

// init_minishell
void	init_minishell(int *pid);

// read_input
char	*read_input(int pid);

// sig_handler
void	set_signal(void);

// term
void	set_terminal(void);

// utils
void	set_pid(int	*pid);

#endif