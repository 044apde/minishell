/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:31:01 by shikim            #+#    #+#             */
/*   Updated: 2023/07/24 20:51:07 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*find_command(t_token *list, t_execute *pack)
{
	list = list->next;
	if (list->type == REDIR_IN || list->type == REDIR_OUT)
		list = list->next->next;
	return (list);
}

int	is_operator2(t_token *list)
{
	if (list->type == PIPE || list->type == REDIR_IN || list->type == REDIR_OUT || list->type == HEREDOC || list->type == APPEND)
		return (TRUE);
	return (FALSE);
}

char	**make_cmd_option(t_token *cmd_node, t_execute *pack)
{
	char	**cmd_option;
	int		count;
	int		index;
	t_token	*list;

	list = cmd_node;
	count = 0;
	while (list != NULL && is_operator2(list) == FALSE && ++count)
		list = list->next;
	cmd_option = (char **)malloc(sizeof(char *) * (count + 1));
	cmd_option[count] = NULL;
	index = 0;
	list = cmd_node;
	while (count-- > 0)
	{
		cmd_option[index++] = ft_strdup(list->token);
		list = list->next;
	}
	return (cmd_option);
}

void	execute_word(t_token *list, t_execute *pack)
{
	char	**cmd_path;
	char	*cmd;
	char	*dangling;
	char	**cmd_option;

	cmd_path = ft_split(get_env(pack->env_list, "PATH"), ':');
	cmd_option = make_cmd_option(list, pack);
	while(*cmd_path != NULL)
	{
		cmd = ft_strjoin(*cmd_path, "/");
		dangling = cmd;
		cmd = ft_strjoin(cmd, list->token);
		free(dangling);
		if (access(cmd, F_OK) == 0)
		{
			execve(cmd, cmd_option, NULL);
			return ;
		}
		free(cmd);
		cmd_path++;
	}
	execve(list->token, cmd_option, NULL);
	// printf("\033[0;31mohmybash# %s: command not found\033[0;0m\n", list->token);
	return ;
}