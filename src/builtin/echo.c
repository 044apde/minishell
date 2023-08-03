/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:26:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/03 14:57:50 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_echo(t_token *token_list)
{
	int	i;

	i = 0;
	if (token_list->next == NULL)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	if (compare_str(token_list->next->token, "-n") == TRUE)
		i = 1;
	while (token_list->next != NULL)
	{
		if (compare_str(token_list->next->token, "-n") == TRUE)
			token_list = token_list->next;
		else if (token_list->next->type == REDIR_IN || token_list->next->type == REDIR_OUT)
			token_list = token_list->next->next;
		else
		{
			ft_putstr_fd(token_list->next->token, 1);
			if (token_list->next->next != NULL)
				ft_putstr_fd(" ", 1);
			token_list = token_list->next;
		}
	}
	if (i == 0)
		ft_putstr_fd("\n", 1);
	return ;
}
