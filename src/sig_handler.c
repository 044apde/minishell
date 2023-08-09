/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:14 by shikim            #+#    #+#             */
/*   Updated: 2023/08/09 16:22:08 by hyungjup         ###   ########.fr       */
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

void	child_handler(int sig)
{
	printf("I'm child process\n");
	return ;
}

void	term_handler(void)
{
	write(1, "\033[0;35m", ft_strlen("\033[0;35m"));
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
