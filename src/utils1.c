/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:59:07 by shikim            #+#    #+#             */
/*   Updated: 2023/08/09 15:41:19 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pid(int	*pid)
{
	*pid = getpid();
	return ;
}

void	exit_program(char *s)
{
	printf("\033[0;31mError: %s\033[0;0m\n", s);
	exit(1);
}

void	check_exit_code(void)
{
	if (g_exit_code == 100)
		exit (0);
	return ;
}