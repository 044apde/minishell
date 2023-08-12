/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:13:49 by shikim            #+#    #+#             */
/*   Updated: 2023/08/11 18:47:40 by shikim           ###   ########.fr       */
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

	execute = (t_execute *)malloc(sizeof(t_execute));
	execute->n_of_process = count_pipe(token_list) + 1;
	execute->count = -1;
	execute->s_n_of_process = execute->n_of_process;
	execute->env_list = env_list;
	if (pipe(execute->pipe_fd) == -1)
		exit_program("fail to call system");
	return (execute);
}

t_execute	*init_and_process(t_token *token_list, t_env_list *env_list)
{
	t_execute	*pack;

	pack = init_execute(token_list, env_list);
	remove_heredoc_file();
	heredoc_process(token_list);
	return (pack);
}

void	execute(t_token *token_list, t_env_list *env_list)
{
	t_execute	*pack;
	int			status;
	int			pid;

	if (token_list == NULL || token_list->next == NULL)
		return ;
	pack = init_and_process(token_list, env_list);
	signal(SIGINT, SIG_IGN);
	while (pack->n_of_process-- > 0)
	{
		if (is_pipe(token_list) == FALSE && is_builtin(token_list) == TRUE)
		{
			pack->s_n_of_process--;
			execute_builtin(token_list, env_list);
			break ;
		}
		pid = fork();
		if (pid != 0)
		{
			waitpid(pid, &status, 0);
			g_exit_code = WEXITSTATUS(status);
		}
		pack->count = pack->count + 1;
		if (pid == 0)
		{
			token_list = move_list(pack->count, token_list);
			if (token_list == NULL)
				return ;
			execute_command(token_list, pack, env_list);
			exit(0);
		}
	}
	signal(SIGINT, int_handler);
	return ;
}
