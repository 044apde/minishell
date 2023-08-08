/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:14 by shikim            #+#    #+#             */
/*   Updated: 2023/08/08 17:59:29 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	int_handler(int sig)
{
	sig++;
	printf("parent handler on\n");
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	child_handler(int sig)
{
	sig++;
	printf("parent handler on\n");
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	term_handler(void)
{
	write(1, "\033[0;35m", ft_strlen("\033[0;35m"));
	write(1, "exit\n", 5);
	exit(0);
	return ;
}

// SIG_QUIT
// 미니쉘 프로세스에 시그널이 들어온 경우.
// 다른 프로그램을 실행했을 때 시그널이 들어온 경우를 다르게 처리해야 합니다.
// 미완성
void	quit_handler(void)
{
	return ;
}

void	set_signal(struct sigaction act_new)
{
	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
	return ;
}
