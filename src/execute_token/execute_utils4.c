/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:31:01 by shikim            #+#    #+#             */
/*   Updated: 2023/08/17 23:17:48 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*find_command(t_token *list)
{
	if (list->token == NULL)
		return (NULL);
	while (list != NULL && list->type != PIPE)
	{
		if (is_operator2(list) == TRUE)
			list = list->next;
		else if (list->prev->token != NULL && is_operator3(list->prev) == TRUE)
			list = list->next;
		else
			return (list);
	}
	if (list->type == PIPE)
		return (NULL);
	return (list);
}

char	**make_cmd_option(t_token *cmd_node)
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

void	cmd_process(t_env_list *env_list, \
					const char *cmd, char **cmd_option)
{
	execve(cmd, cmd_option, env_list->envp_copy);
	perror("\033[0;31mohmybash# ");
	if (errno == 13)
		exit(126);
	exit(127);
}

void	execute_word(t_token *list, t_execute *pack, t_env_list *env_list)
{
	char	*cmd;
	char	**cmd_option;

	if (list == NULL)
		exit (0);
	cmd_option = make_cmd_option(list);
	if (list->token[0] == '.' || list->token[0] == '/')
	{
		check_file_exist(list->token);
		cmd_process(env_list, list->token, cmd_option);
	}
	else if (is_builtin(list) == TRUE)
	{
		execute_builtin(list, env_list);
		exit (g_exit_code);
	}
	cmd = make_cmd(list, pack);
	if (cmd == NULL)
	{
		error_cmd_not_found(list->token);
		exit(127);
	}
	cmd_process(env_list, cmd, cmd_option);
}
