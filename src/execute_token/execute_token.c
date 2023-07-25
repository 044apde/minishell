/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:13:49 by shikim            #+#    #+#             */
/*   Updated: 2023/07/25 03:49:17 by shikim           ###   ########.fr       */
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
	int			n;

	if (token_list == NULL)
		return ;
	pack = init_execute(token_list, env_list);
	while (pack->n_of_process-- > 0) {
		pid = fork();
		pack->count = pack->count + 1;
		if (pid != 0) {
			continue;
		} else if (pid == 0) {
			usleep(100);
			t_token *list = move_list(pack->count, token_list);
			if (list == NULL)
				return;
			remvove_heredoc_file();
			execute_command(list, pack);
			exit(1);
		}
	}
	while (wait(NULL) > 0)
		;
	return ;
}
