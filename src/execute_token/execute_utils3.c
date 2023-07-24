/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/07/24 23:13:02 by shikim           ###   ########.fr       */
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
	while (list != NULL && list->type != REDIR_IN && list->type != HEREDOC)
		list = list->prev;
	return (list);
}

t_token *move_to_redirout(t_token *list)
{
	while (list != NULL && list->type != REDIR_OUT && list->type != APPEND)
		list = list->prev;
	return (list);
}

int	do_redirin(t_token *list, t_execute *pack)
{
	int infile;

	list = move_to_last(list);
	list = move_to_redirin(list);
	if (list == NULL)
		return (FALSE);
	if (list->type == HEREDOC)
	{
		infile = open(".heredoc", O_CREAT | O_APPEND | O_RDWR, 0777);
		do_heredoc(list, pack, infile);
		close(infile);
	}
	infile = open(".heredoc", O_RDONLY);
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
	if (list == NULL)
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
