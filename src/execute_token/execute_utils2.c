/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/07/31 18:53:42 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_first_command(t_token *list, t_execute *pack, \
								t_env_list *env_list)
{
	int	origin_stdout;
	int	heredoc_fd;

	printf("\033[0;35mFIRST COMMAND EXECUTE\033[0;0m\n");
	list = list->next;
	if (is_pipe(list) == TRUE)
	{
		close(pack->pipe_fd[0]);
		origin_stdout = dup(STDOUT_FILENO);
		dup2(pack->pipe_fd[1], STDOUT_FILENO);
	}
	if ((heredoc_fd = do_redirin(list, pack, origin_stdout)) == ERROR)
		return ;
	if (do_redirout(list, pack) == ERROR)
	{
		close(heredoc_fd);
		return ;
	}
	list = find_command(list, pack);
	execute_word(list, pack, env_list);
	close(heredoc_fd);
	if (is_pipe(list) == TRUE)
	{
		dup2(origin_stdout, STDOUT_FILENO);
		close(origin_stdout);
	}
	wait(NULL);
	close(heredoc_fd);
	return ;
}

void	execute_middle_command(t_token *list, t_execute *pack, \
								t_env_list *env_list)
{
	int		origin_stdout;

	printf("\033[0;35mMIDDLE COMMAND EXECUTE\033[0;0\n");
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	origin_stdout = dup(STDOUT_FILENO);
	dup2(pack->pipe_fd[1], STDOUT_FILENO);
	if (do_redirin(list, pack, origin_stdout) == ERROR)
		return ;
	if (do_redirout(list, pack) == ERROR)
		return ;
	list = find_command(list, pack);
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

	printf("\033[0;35mLAST COMMAND EXECUTE\033[0;0m\n");
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	origin_stdout = dup(STDOUT_FILENO);
	if (do_redirin(list, pack, origin_stdout) == ERROR)
		return ;
	if (do_redirout(list, pack) == ERROR)
		return ;
	list = find_command(list, pack);
	execute_word(list, pack, env_list);
	wait(NULL);
	return ;
}
