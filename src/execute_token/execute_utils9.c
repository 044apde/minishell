/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:50:07 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 15:50:47 by shikim           ###   ########.fr       */
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
