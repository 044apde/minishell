/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:26:00 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/16 17:29:03 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	echo_process(t_token *token_list)
{
	int	flag;

	flag = 0;
	token_list = token_list->next;
	if (compare_str(token_list->token, "-n") == TRUE)
		token_list = token_list->next;
	while (token_list != NULL && token_list->type != PIPE)
	{
		if (is_operator3(token_list) == TRUE)
			token_list = token_list->next->next;
		else
		{
			write(1, token_list->token, ft_strlen(token_list->token));
			flag = 1;
			if (flag == 1)
				write(1, " ", 1);
			token_list = token_list->next;
		}
	}
	return ;
}

void	ft_echo(t_token *token_list)
{
	g_exit_code = 0;
	if (token_list->next == NULL)
		ft_putstr_fd("\n", 1);
	else
	{
		echo_process(token_list);
	}
	if (compare_str(token_list->next->token, "-n") == FALSE)
		ft_putstr_fd("\n", 1);
	return ;
}
