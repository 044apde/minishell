/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:13:49 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 17:42:57 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	wait_child(t_linked_list *pid_list, t_execute *pack)
{
	int				status;
	t_linked_list	*origin;

	close(pack->pipe_fd[0]);
	origin = pid_list;
	while (pid_list != NULL)
	{
		waitpid(pid_list->fd, &status, 0);
		ctrl_exit_status_with_singal(status);
		pid_list = pid_list->next;
	}
	free_l_list(origin);
	signal(SIGINT, int_handler);
	free(pack);
}

void	ctrl_pipe(int i, t_execute *pack)
{
	if (i > 0)
		close(pack->tmp);
	pack->tmp = pack->pipe_fd[0];
	close(pack->pipe_fd[1]);
	return ;
}

void	do_execute(t_execute *pack, t_token *token_list, t_env_list *env_list)
{
	int				pid;
	int				i;
	t_linked_list	*pid_list;

	i = -1;
	pid_list = NULL;
	while (++i < pack->n_of_process)
	{
		if (pipe(pack->pipe_fd) == -1)
			exit_program("fail to call system");
		if (is_pipe(token_list) == FALSE && is_builtin(token_list) == TRUE)
		{
			execute_builtin(token_list, env_list);
			break ;
		}
		pid = fork();
		pid_list = insert_l_node(pid_list, pid);
		pack->count = pack->count + 1;
		if (pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			token_list = move_list(pack->count, token_list);
			if (token_list == NULL)
				return ;
			execute_command(token_list, pack, env_list);
			exit(0);
		}
		ctrl_pipe(i, pack);
	}
	wait_child(pid_list, pack);
	return ;
}

void	execute(t_token *token_list, t_env_list *env_list, t_token *origin_list)
{
	t_execute		*pack;

	if (token_list == NULL || token_list->next == NULL)
		return ;
	pack = init_and_process(token_list, env_list, origin_list);
	signal(SIGINT, SIG_IGN);
	do_execute(pack, token_list, env_list);
}
