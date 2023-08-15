/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:50:07 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 16:39:09 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_operator2(t_token *list)
{
	if (list->type == PIPE || list->type == REDIR_IN || \
		list->type == REDIR_OUT || list->type == HEREDOC || \
		list->type == APPEND)
		return (TRUE);
	return (FALSE);
}

int	is_operator3(t_token *list)
{
	if (list->type == REDIR_IN || \
		list->type == REDIR_OUT || list->type == HEREDOC || \
		list->type == APPEND)
		return (TRUE);
	return (FALSE);
}

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
	return (execute);
}

t_execute	*init_and_process(t_token *token_list, t_env_list *env_list, \
								t_token *origin_list)
{
	t_execute	*pack;

	pack = init_execute(token_list, env_list);
	remove_heredoc_file();
	heredoc_process(origin_list, token_list);
	return (pack);
}
