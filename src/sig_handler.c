/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:14 by shikim            #+#    #+#             */
/*   Updated: 2023/08/18 19:58:44 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	int_handler(int sig)
{
	sig++;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	term_handler(void)
{
	remove_heredoc_file();
	write(1, "exit\n", 5);
	exit(0);
	return ;
}

void	set_signal(void)
{
	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
