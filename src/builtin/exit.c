/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:25:04 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/18 19:59:36 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	check_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i] == '+')
		;
	if (str[i] == '-')
		return (FALSE);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i++]) == FALSE)
			return (FALSE);
	}
	if (ft_atoi(str) == -1)
		return (FALSE);
	return (TRUE);
}

void	ft_exit(t_token *token_list)
{
	if (token_list->next == NULL)
		exit(0);
	if (token_list->next->next != NULL && \
			is_operator(token_list->next->next->token) == FALSE)
	{
		ft_putstr_fd("ohmybash# exit: ", 2);
		ft_putstr_fd("Too many arguments\n", 2);
		g_exit_code = 1;
		return ;
	}
	else if (check_num(token_list->next->token) == FALSE)
	{
		ft_putstr_fd("ohmybash# exit: ", 2);
		ft_putstr_fd(token_list->next->token, 2);
		ft_putstr_fd(": Check argument\n", 2);
		exit(255);
	}
	exit(ft_atoi(token_list->next->token));
}
