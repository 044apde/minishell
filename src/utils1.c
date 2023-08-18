/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:59:07 by shikim            #+#    #+#             */
/*   Updated: 2023/08/18 19:59:22 by shikim           ###   ########.fr       */
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
		ft_putstr_fd("ohmybash# Error found\n", 2);
	else
	{
		ft_putstr_fd("ohmybash# ", 2);
		write(2, s, ft_strlen(s));
		ft_putstr_fd("\n", 2);
	}
	exit(1);
}

void	error_cmd_not_found(char *string)
{
	if (string == NULL)
		ft_putstr_fd("ohmybash# Command not found\n", 2);
	else
	{
		ft_putstr_fd("ohmybash# ", 2);
		write(2, string, ft_strlen(string));
		ft_putstr_fd(": Command not found\n", 2);
	}
	return ;
}

void	error_cmd_no_file_dir(char *string)
{
	if (string == NULL)
	{
		ft_putstr_fd("ohmybash# ", 2);
		ft_putstr_fd(" No such file or directory\n", 2);
	}
	else
	{
		ft_putstr_fd("ohmybash# ", 2);
		write(2, string, ft_strlen(string));
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	return ;
}
