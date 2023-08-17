/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 22:14:03 by shikim            #+#    #+#             */
/*   Updated: 2023/08/17 15:24:35 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*move_to_last(t_token *list)
{
	while (list->next != NULL && list->next->type != PIPE)
		list = list->next;
	return (list);
}

t_token	*move_to_redirin(t_token *list)
{
	t_token	*redir;
	t_token	*heredoc;

	redir = list;
	heredoc = list;
	while (redir != NULL && redir->type != REDIR_IN && redir->type != PIPE)
		redir = redir->prev;
	if (redir != NULL && redir->type != PIPE)
		return (redir);
	while (heredoc != NULL && heredoc->type != HEREDOC \
				&& heredoc->type != PIPE)
		heredoc = heredoc->prev;
	if (heredoc != NULL && heredoc->type != PIPE)
		return (heredoc);
	return (NULL);
}

t_token	*move_to_redirout(t_token *list)
{
	while (list != NULL && list->type != REDIR_OUT && \
			list->type != APPEND && list->type != PIPE)
		list = list->prev;
	return (list);
}

int	do_redirin(t_token *list)
{
	int		infile;

	list = move_to_last(list);
	list = move_to_redirin(list);
	if (list == NULL || list->type == PIPE)
		return (FALSE);
	infile = open(list->next->token, O_RDONLY, 0777);
	if (infile == ERROR)
	{
		ft_putstr_fd("\033[0;31mohmybash#: ", 2);
		ft_putstr_fd(list->next->token, 2);
		ft_putstr_fd(": can't open file\033[0;0m\n", 2);
		g_exit_code = 126 ;
		exit(g_exit_code);
		return (ERROR);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	return (TRUE);
}

int	do_redirout(t_token *list)
{
	int	outfile;

	outfile = 0;
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
		ft_putstr_fd("\033[0;31mohmybash# :", 2);
		write(2, list->next->token, ft_strlen(list->next->token));
		ft_putstr_fd(": can't open file\033[0;0m\n", 2);
		exit(126);
		return (ERROR);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	return (TRUE);
}
