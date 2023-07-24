/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:13:49 by shikim            #+#    #+#             */
/*   Updated: 2023/07/24 20:46:45 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_pipe(t_token *token_list)
{
	int		count;

	count = 0;
	token_list = token_list->next;
	while (token_list != NULL)
	{
		if (token_list->type == PIPE)
			++count;
		token_list = token_list->next;
	}
	return (count);
}

t_execute	*init_execute(t_token *token_list, t_env_list *env_list)
{
	t_execute	*execute;
	int			**pipe_fd;

	execute = (t_execute *)malloc(sizeof(t_execute));
	pipe_fd = (int **)malloc(sizeof(int *) * 2);
	pipe_fd[0] = (int *)malloc(sizeof(int));
	pipe_fd[1] = (int *)malloc(sizeof(int));
	execute->n_of_process = count_pipe(token_list) + 1;
	execute->pipe_fd = pipe_fd;
	execute->count = -1;
	execute->s_n_of_process = execute->n_of_process;
	execute->env_list = env_list;
	return (execute);
}

void	execute(t_token *token_list, t_env_list *env_list)
{
	t_execute	*pack;
	int			pid;
	int			n;

	if (token_list == NULL)
		return ;
	pack = init_execute(token_list, env_list);
	while (pack->n_of_process-- > 0)
	{
		pid = fork();
		pack->count = pack->count + 1;
		if (pid != 0)
			waitpid(pid, NULL, 0); 
		else if (pid == 0)
		{
			usleep(100);
			t_token *list = move_list(pack->count, token_list);
			if (list == NULL)
				return ;
			execute_command(list, pack);
			exit (1);
		}
	}
	return ;
}
