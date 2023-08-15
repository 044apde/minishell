/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:16:11 by shikim            #+#    #+#             */
/*   Updated: 2023/08/14 22:42:08 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	custom_wxd(int status)
{
	return ((status & 0x7F) == 0);
}

int	custom_wss(int status)
{
	return ((status >> 8) & 0xFF);
}

int	custom_wgd(int status)
{
	return (((status & 0x7F) != 0) && (((status >> 8) & 0xFF) == 0));
}

int	custom_wsg(int status)
{
	return (status & 0x7F);
}

void	free_l_list(t_linked_list *pid_list)
{
	t_linked_list	*temp;

	while (pid_list != NULL)
	{
		temp = pid_list;
		pid_list = pid_list->next;
		free(temp);
	}
}
