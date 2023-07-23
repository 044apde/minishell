/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/07/23 22:38:04 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_first_command(t_token *list, t_execute *pack)
{
	char	*command;

	close(pack->pipe_fd[0]);
	dup2(pack->pipe_fd[1], STDOUT_FILENO);

	while (list->next != NULL && list->next->type != PIPE)
		list = list->next;

	// execve 처리 해야함.
	return ;
}

void	execute_middle_command(t_token *list, t_execute *pack)
{
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	dup2(pack->pipe_fd[1], STDOUT_FILENO);
	return ;
}

void	execute_last_command(t_token *list, t_execute *pack)
{
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	return ;
}
