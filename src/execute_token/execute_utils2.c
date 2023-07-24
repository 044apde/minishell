/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/07/24 23:23:35 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	execute_first_command(t_token *list, t_execute *pack)
{
	char	*command;
	char	**cmd_path;
	int		redir;

	printf("\033[0;35mFIRST COMMAND EXECUTE\033[0;0m\n");
	list = list->next;
	if (is_pipe(list) == TRUE)
	{
		close(pack->pipe_fd[0]);
		dup2(pack->pipe_fd[1], STDOUT_FILENO);
	}
	redir = do_redirin(list, pack);
	if (redir == ERROR)
		return ;
	if (do_redirout(list, pack) == ERROR)
		return ;
	list = find_command(list, pack);
	execute_word(list, pack);
	return ;
}

void	execute_middle_command(t_token *list, t_execute *pack)
{
	printf("\033[0;35mMIDDLE COMMAND EXECUTE\033[0;0\n");
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	dup2(pack->pipe_fd[1], STDOUT_FILENO);
	if (do_redirin(list, pack) == ERROR)
		return ;
	if (do_redirout(list, pack) == ERROR)
		return ;
	list = find_command(list, pack);
	execute_word(list, pack);
	return ;
}

void	execute_last_command(t_token *list, t_execute *pack)
{
	printf("\033[0;35mLAST COMMAND EXECUTE\033[0;0m\n");
	dup2(pack->pipe_fd[0], STDIN_FILENO);
	if (do_redirin(list, pack) == ERROR)
		return ;
	if (do_redirout(list, pack) == ERROR)
		return ;
	list = find_command(list, pack);
	execute_word(list, pack);
	return ;
}
