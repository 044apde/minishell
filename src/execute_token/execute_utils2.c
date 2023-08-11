/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/08/11 11:46:41 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_first_command(t_token *list, t_execute *pack, \
								t_env_list *env_list)
{
	int	origin_stdout;

	origin_stdout = 0;
	list = list->next;
	if (is_pipe(list) == TRUE)
	{
		close(pack->pipe_fd[0]);
		origin_stdout = dup(STDOUT_FILENO);
		dup2(pack->pipe_fd[1], STDOUT_FILENO);
	}
	if (do_redirin(list) == ERROR)
		return ;
	// if (do_redirout(list) == ERROR)
	// 	return ;
	list = find_command(list);
	execute_word(list, pack, env_list);
	if (is_pipe(list) == TRUE)
	{
		dup2(origin_stdout, STDOUT_FILENO);
		close(origin_stdout);
	}
	wait(NULL);
	return ;
}

void	execute_middle_command(t_token *list, t_execute *pack, \
								t_env_list *env_list)
{
	int		origin_stdout;

	dup2(pack->pipe_fd[0], STDIN_FILENO);
	origin_stdout = dup(STDOUT_FILENO);
	dup2(pack->pipe_fd[1], STDOUT_FILENO);
	if (do_redirin(list) == ERROR)
		return ;
	if (do_redirout(list) == ERROR)
		return ;
	list = find_command(list);
	execute_word(list, pack, env_list);
	dup2(origin_stdout, STDOUT_FILENO);
	close(origin_stdout);
	wait(NULL);
	return ;
}

void	execute_last_command(t_token *list, t_execute *pack, \
							t_env_list *env_list)
{
	int		origin_stdout;
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	origin_stdout = dup(STDOUT_FILENO);
	if (do_redirin(list) == ERROR)
		return ;
	if (do_redirout(list) == ERROR)
		return ;
	list = find_command(list);
	execute_word(list, pack, env_list);
	wait(NULL);
	return ;
}
