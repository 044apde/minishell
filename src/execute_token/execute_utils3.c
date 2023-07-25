/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/07/25 16:46:43 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*move_to_last(t_token *list)
{
	while (list->next != NULL && list->next->type != PIPE)
		list = list->next;
	return (list);
}

t_token *move_to_redirin(t_token *list)
{
	while (list != NULL && list->type != REDIR_IN && list->type != HEREDOC && list->type != PIPE)
		list = list->prev;
	return (list);
}

t_token *move_to_redirout(t_token *list)
{
	while (list != NULL && list->type != REDIR_OUT && list->type != APPEND && list->type != PIPE)
		list = list->prev;
	return (list);
}

int	do_redirin(t_token *list, t_execute *pack, int origin_stdout)
{
	int infile;

	list = move_to_last(list);
	list = move_to_redirin(list);
	if (list == NULL || list->type == PIPE)
		return (FALSE);
	if (list->type == HEREDOC)
	{
		printf("heredoc on\n");
		infile = open("src/execute_token/.heredoc", O_CREAT | O_APPEND | O_RDWR, 0777);
		dup2(origin_stdout, STDOUT_FILENO);
		do_heredoc(list, pack, infile);
		if (is_pipe(list) == TRUE)
			dup2(pack->pipe_fd[1], STDOUT_FILENO);
		close(infile);
		infile = open("src/execute_token/.heredoc", O_RDONLY, 0777);
	}
	else
		infile = open(list->next->token, O_RDONLY, 0777);
	if (infile == ERROR)
	{
		printf("\033[31mohmybash# %s: No such file or directory\033[0m\n", list->next->token);
		return (ERROR);
	}
	dup2(infile, STDIN_FILENO);
	return (HEREDOC);
}

int	do_redirout(t_token *list, t_execute *pack)
{
	int outfile;

	list = move_to_last(list);
	list = move_to_redirout(list);
	if (list == NULL || list->type == PIPE)
		return (FALSE);
	if (list->type == APPEND)
		outfile = open(list->next->token, O_CREAT | O_RDWR | O_APPEND, 0777);
	else if (list->type == REDIR_OUT)
		outfile = open(list->next->token, O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (outfile == ERROR)
	{
		printf("\033[0;35mohmybash#: %s: can't open file\033[0;0m\n", list->next->token);
		return (ERROR);
	}
	dup2(outfile, STDOUT_FILENO);
	return (TRUE);
}
