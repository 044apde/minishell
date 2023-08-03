/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:13:49 by shikim            #+#    #+#             */
/*   Updated: 2023/08/03 15:00:34 by hyungjup         ###   ########.fr       */
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
	execute->n_of_process = count_pipe(token_list) + 1;
	execute->count = -1;
	execute->s_n_of_process = execute->n_of_process;
	execute->env_list = env_list;
	if (pipe(execute->pipe_fd) == -1)
		exit_program("fail to call system");
	return (execute);
}

void	execute(t_token *token_list, t_env_list *env_list)
{
	t_execute	*pack;
	int			pid;
	t_token		*list;
	int			status;

	if (token_list == NULL)
		return ;
	pack = init_execute(token_list, env_list);
	remove_heredoc_file();
	heredoc_process(token_list, pack);
	while (pack->n_of_process-- > 0)
	{
		if (is_pipe(token_list) == FALSE && is_builtin(token_list->next) == TRUE)
		{
			if (execute_builtin(token_list->next, env_list, pack) == ERROR)
				return ;
			break ;
		}
		pid = fork();
		pack->count = pack->count + 1;
		if (pid == 0)
		{
			list = move_list(pack->count, token_list);
			if (list == NULL)
				return ;
			execute_command(list, pack, env_list);
			exit(1);
		}
	}
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status) || WIFCONTINUED(status))
			break ;
	}
	return ;
}
