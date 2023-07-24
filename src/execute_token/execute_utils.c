/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:54:44 by shikim            #+#    #+#             */
/*   Updated: 2023/07/24 15:43:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	execute_command(t_token *list, t_execute *pack)
{
	int	order;

	order = set_order(pack);
	if (order == FIRST)
		execute_first_command(list, pack);
	else if (order == MIDDLE)
		execute_middle_command(list, pack);
	else
		execute_last_command(list, pack);
	return ;
}
