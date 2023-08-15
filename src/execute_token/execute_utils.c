/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:54:44 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 17:48:43 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_exit(t_token *list)
{
	while (list != NULL)
	{
		if (compare_str(list->token, "exit") == TRUE)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

int	is_pipe(t_token *list)
{
	while (list != NULL)
	{
		if (list->type == PIPE)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

t_token	*move_list(int count, t_token *list)
{
	while (count > 0 && list != NULL)
	{
		if (list->type == PIPE)
			--count;
		list = list->next;
	}
	return (list);
}

static int	set_order(t_execute *pack)
{
	if (pack->count == 0)
		return (FIRST);
	else if (pack->count == pack->s_n_of_process - 1)
		return (LAST);
	else
		return (MIDDLE);
}

void	execute_command(t_token *list, t_execute *pack, t_env_list *env_list)
{
	int	order;

	if (list == NULL)
		return ;
	signal(SIGINT, SIG_DFL);
	order = set_order(pack);
	if (order == FIRST)
		execute_first_command(list, pack, env_list);
	else if (order == MIDDLE)
		execute_middle_command(list, pack, env_list);
	else
		execute_last_command(list, pack, env_list);
	return ;
}
