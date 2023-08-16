/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/08/16 20:15:36 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_heredoc_file(void)
{
	int			i;
	char		*heredoc_file_name;
	static int	here_doc_file_count;
	char		*tmp_itoa;

	i = 1;
	here_doc_file_count = 1;
	while (1)
	{
		tmp_itoa = ft_itoa(i);
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", \
							tmp_itoa);
		if (access(heredoc_file_name, F_OK) < 0)
		{
			free(heredoc_file_name);
			free(tmp_itoa);
			break ;
		}
		here_doc_file_count++;
		i++;
		free(heredoc_file_name);
		free(tmp_itoa);
	}
	return (here_doc_file_count);
}

void	remove_heredoc_file(void)
{
	int			i;
	char		*heredoc_file_name;
	static int	here_doc_file_count;
	char		*tmp_itoa;

	i = 1;
	here_doc_file_count = count_heredoc_file();
	while (i < here_doc_file_count)
	{
		tmp_itoa = ft_itoa(i);
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", \
							tmp_itoa);
		if (access(heredoc_file_name, F_OK) < 0)
		{
			free(tmp_itoa);
			break ;
		}
		unlink(heredoc_file_name);
		free(heredoc_file_name);
		free(tmp_itoa);
		i++;
	}
	return ;
}

char	*make_cmd(t_token *list, t_execute *pack)
{
	char	**cmd_path;
	char	*cmd;
	char	*dangling;
	char	*env;

	env = get_env(pack->env_list, "PATH");
	if (env == NULL)
	{
		printf("\033[0;31mohmybash# : %s: No such file or directory\033[0;0m\n", \
					list->token);
		exit(127);
	}
	cmd_path = ft_split(env, ':');
	while (*cmd_path != NULL)
	{
		cmd = ft_strjoin(*cmd_path, "/");
		dangling = cmd;
		cmd = ft_strjoin(cmd, list->token);
		free(dangling);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		cmd_path++;
	}
	return (NULL);
}

int	is_redir(t_token *list)
{
	while (list != NULL)
	{
		if (list->type == REDIR_IN || list->type == REDIR_OUT || \
			list->type == APPEND)
			return (TRUE);
	}
	return (FALSE);
}
