/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/08/16 20:14:14 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_first_command(t_token *list, t_execute *pack, \
								t_env_list *env_list)
{
	list = list->next;
	if (is_pipe(list) == TRUE)
	{
		close(pack->pipe_fd[0]);
		dup2(pack->pipe_fd[1], STDOUT_FILENO);
	}
	else
	{
		close(pack->pipe_fd[0]);
		close(pack->pipe_fd[1]);
	}
	if (do_redirin(list) == ERROR)
		return ;
	if (do_redirout(list) == ERROR)
		return ;
	list = find_command(list);
	execute_word(list, pack, env_list);
	return ;
}

void	execute_middle_command(t_token *list, t_execute *pack, \
								t_env_list *env_list)
{
	dup2(pack->tmp, STDIN_FILENO);
	dup2(pack->pipe_fd[1], STDOUT_FILENO);
	close(pack->pipe_fd[0]);
	if (do_redirin(list) == ERROR)
		return ;
	if (do_redirout(list) == ERROR)
		return ;
	list = find_command(list);
	execute_word(list, pack, env_list);
	return ;
}

void	execute_last_command(t_token *list, t_execute *pack, \
							t_env_list *env_list)
{
	dup2(pack->tmp, STDIN_FILENO);
	close(pack->pipe_fd[0]);
	close(pack->pipe_fd[1]);
	if (do_redirin(list) == ERROR)
		return ;
	if (do_redirout(list) == ERROR)
		return ;
	list = find_command(list);
	execute_word(list, pack, env_list);
	return ;
}
