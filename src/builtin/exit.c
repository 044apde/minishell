/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/20 22:26:50 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	print_error_exit(char *str, int flag)
{
	int	exit_num;

	if (flag == 1)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("ohmybash# exit:a", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		exit_num = 255;
	}
	else if (flag == 2)
	{
		exit_num = 1;
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("ohmybash# exit: too many arguments\n", 2);
	}
	return (exit_num);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(int argc, char **argv)
{
	int	i;
	int	exit_num;

	i = 0;
	ft_putstr_fd("exit\n", 2);
	if (argc > 1)
	{
		if (check_num(argv[1]) != 1)
		{
			exit_num = print_error_exit(argv[1], 1);
		}
		else if (argc == 2)
			exit(ft_atoi(argv[1]));
		if (argc > 2)
		{
			ft_putstr_fd("ohmybash# exit: too many arguments\n", 2);
			exit_num = 1;
		}
	}
}
