/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:31:01 by shikim            #+#    #+#             */
/*   Updated: 2023/08/11 18:38:32 by shikim           ###   ########.fr       */
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

t_token	*find_command(t_token *list)
{
	if (list->token == NULL)
		list = list->next;
	while (list != NULL)
	{
		if (is_operator2(list) == TRUE)
			list = list->next;
		else if (list->prev->token != NULL && is_operator3(list->prev) == TRUE)
			list = list->next;
		else
		{
			return (list);
		}
	}
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

void	cmd_process(t_token *list, t_env_list *env_list, \
					const char *cmd, char **cmd_option)
{
	if (cmd == NULL)
	{
		if (compare_str(list->token, "\n") == TRUE)
			printf("\033[0;31mohmybash# : command not found\033[0;0m\n");
		else
			printf("\033[0;31mohmybash# %s: command not found\033[0;0m\n", list->token);
		free(cmd_option);
		exit(127);
		return ;
	}
	execve(cmd, cmd_option, env_list->envp_copy);
	if (compare_str(list->token, "\n") == TRUE)
			printf("\033[0;31mohmybash# : command not found\033[0;0m\n");
	printf("\033[0;31mohmybash# %s: command not found\033[0;0m\n", list->token);
	exit(127);
	free(cmd_option);
}

void	execute_word(t_token *list, t_execute *pack, t_env_list *env_list)
{
	char	*cmd;
	char	**cmd_option;

	if (list->type == HEREDOC)
	{
		cmd_option = make_heredoc_option();
		execve("/bin/cat", cmd_option, env_list->envp_copy);
	}
	else
		cmd_option = make_cmd_option(list);
	if (list->token[0] == '.' || list->token[0] == '/')
	{
		cmd = list->token;
		cmd_process(list, env_list, cmd, cmd_option);
	}
	else if (is_builtin(list) == TRUE)
	{
		execute_builtin(list, env_list);
		exit (g_exit_code);
		free(cmd_option);
		return ;
	}
	else
	{
		cmd = make_cmd(list, pack);
		cmd_process(list, env_list, cmd, cmd_option);
		exit (g_exit_code);
	}
	return ;
}
