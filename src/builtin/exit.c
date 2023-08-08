/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/08 15:38:54 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	print_error_exit(char *str, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("ohmybash# exit: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		g_exit_code = 255;
	}
	else if (flag == 2)
	{
		ft_putstr_fd("exit\n", 2);
		ft_putstr_fd("ohmybash# exit: too many arguments\n", 2);
		g_exit_code = 1;
	}
	return (g_exit_code);
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
	if (token_list->next == NULL)
		g_exit_code = 0;
	else if (token_list->next != NULL)
	{
		if (!check_num(token_list->next->token))
		{
			g_exit_code = print_error_exit(token_list->next->token, 1);
		}
		else
		{
			if (token_list->next->next != NULL)
				g_exit_code = print_error_exit(NULL, 2);
			else
				g_exit_code = ft_atoi(token_list->next->token);
		}
	}
	exit(g_exit_code);
}
