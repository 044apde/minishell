/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:59:07 by shikim            #+#    #+#             */
/*   Updated: 2023/08/17 18:48:43 by shikim           ###   ########.fr       */
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
	if (s == NULL)
		ft_putstr_fd("\033[0;31mohmybash# Error found\033[0;0m\n", 2);
	else
	{
		ft_putstr_fd("\033[0;31mohmybash# ", 2);
		write(2, s, ft_strlen(s));
		ft_putstr_fd("\033[0;0m\n", 2);
	}
	exit(1);
}

void	error_cmd_not_found(char *string)
{
	if (string == NULL)
		ft_putstr_fd("\033[0;31mohmybash# Command not found\033[0;0m\n", 2);
	else
	{
		ft_putstr_fd("\033[0;31mohmybash# ", 2);
		write(2, string, ft_strlen(string));
		ft_putstr_fd(": Command not found\033[0;0m\n", 2);
	}
	return ;
}

void	error_cmd_no_file_dir(char *string)
{
	if (string == NULL)
	{
		ft_putstr_fd("\033[0;31mohmybash# ", 2);
		ft_putstr_fd(" No such file or directory\033[0;0m\n", 2);
	}
	else
	{
		ft_putstr_fd("\033[0;31mohmybash# ", 2);
		write(2, string, ft_strlen(string));
		ft_putstr_fd(": No such file or directory\033[0;0m\n", 2);
	}
	return ;
}
