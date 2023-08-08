/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 20:13:49 by shikim            #+#    #+#             */
/*   Updated: 2023/08/08 18:09:12 by hyungjup         ###   ########.fr       */
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

/*ohmybash 문구가 두개 나오는 이유가 자식프로세스 에서 ctrl+c를 누르면
부모프로세스에서도 프롬프트를 출력하고, 자식프로세스에서도 빠져나오면서 출력하기 때문이다.*/
void	execute(t_token *token_list, t_env_list *env_list, struct sigaction act_new)
{
	t_execute	*pack;
	int			status;
	int			pid;

	if (token_list == NULL)
		return ;
	pack = init_and_process(token_list, env_list);
	signal(SIGINT, SIG_IGN);
	while (pack->n_of_process-- > 0)
	{
		if (is_pipe(token_list) == FALSE && \
			is_builtin(token_list->next) == TRUE)
		{
			if (execute_builtin(token_list->next, env_list) == ERROR)
				return ;
			break ;
		}
		pid = fork();
		pack->count = pack->count + 1;
		if (pid == 0)
		{
			signal(SIGINT, child_handler);
			token_list = move_list(pack->count, token_list);
			if (token_list == NULL)
				return ;
			execute_command(token_list, pack, env_list);
			exit(1);
		}
	}
	while (pack->s_n_of_process-- > 0)
	{
		wait(&status);
	}
	return ;
}
