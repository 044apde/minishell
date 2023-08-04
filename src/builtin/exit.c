/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/03 18:45:04 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	print_error_exit(char *str, int flag)
{
	int	exit_num;

	exit_num = 0;
	if (flag == 1)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("ohmybash# exit: ", 2);
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

static int	check_num(char *str)
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

void	ft_exit(t_token *token_list)
{
	int	exit_num;

	exit_num = 0;
	if (token_list->next == NULL)
		exit_num = 0;
	else if (token_list->next != NULL)
	{
		if (!check_num(token_list->next->token))
		{
			exit_num = print_error_exit(token_list->next->token, 1);
		}
		else
		{
			if (token_list->next->next != NULL)
				exit_num = print_error_exit(NULL, 2);
			else
				exit_num = ft_atoi(token_list->next->token);
		}
	}
	exit(exit_num);
}
