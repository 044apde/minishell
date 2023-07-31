/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:33:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/31 18:51:57 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*find_builtin_cmd(t_token *token_list)
{
	t_token	*list;
	char	*cmd;

	list = token_list;
	cmd = NULL;
	while (list != NULL && list->type != PIPE)
	{
		if (list->type == REDIR_IN || list->type == REDIR_OUT)
		{
			if (list->next != NULL && list->next->next != NULL)
				list = list->next->next;
			else
				break ;
		}
		else if (list->type == WORD && !cmd)
			cmd = list->token;
		if (list != NULL)
			list = list->next;
	}
	return (cmd);
}

int	is_builtin(t_token *token_list)
{
	char	*token;

	token = find_builtin_cmd(token_list);
	if (token == NULL)
		return (FALSE);
	if (compare_str(token, "echo") == TRUE)
		return (TRUE);
	else if (compare_str(token, "cd") == TRUE)
		return (TRUE);
	else if (compare_str(token, "pwd") == TRUE)
		return (TRUE);
	else if (compare_str(token, "export") == TRUE)
		return (TRUE);
	else if (compare_str(token, "unset") == TRUE)
		return (TRUE);
	else if (compare_str(token, "env") == TRUE)
		return (TRUE);
	else if (compare_str(token, "exit") == TRUE)
		return (TRUE);
	return (FALSE);
}

int	execute_builtin(t_token *token_list, t_env_list *env_list)
{
	if (compare_str(token_list->token, "echo") == TRUE)
		ft_echo(token_list);
	else if (compare_str(token_list->token, "cd") == TRUE)
		ft_cd(env_list, token_list);
	else if (compare_str(token_list->token, "pwd") == TRUE)
		ft_pwd();
	else if (compare_str(token_list->token, "export") == TRUE)
		ft_export(env_list, token_list);
	else if (compare_str(token_list->token, "unset") == TRUE)
		ft_unset(env_list, token_list);
	else if (compare_str(token_list->token, "env") == TRUE)
		ft_env(env_list);
	else if (compare_str(token_list->token, "exit") == TRUE)
		ft_exit(token_list);
	return (0);
}