/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/08/08 14:43:39 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_heredoc_file(void)
{
	int			i;
	char		*heredoc_file_name;
	static int	here_doc_file_count;

	i = 1;
	here_doc_file_count = 1;
	while (1)
	{
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", \
							ft_itoa(i));
		if (access(heredoc_file_name, F_OK) < 0)
		{
			free(heredoc_file_name);
			break ;
		}
		here_doc_file_count++;
		i++;
		free(heredoc_file_name);
	}
	return (here_doc_file_count);
}

void	remove_heredoc_file(void)
{
	int			i;
	char		*heredoc_file_name;
	static int	here_doc_file_count;

	i = 1;
	here_doc_file_count = count_heredoc_file();
	while (i < here_doc_file_count)
	{
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", \
							ft_itoa(i));
		if (access(heredoc_file_name, F_OK) < 0)
			break ;
		unlink(ft_strjoin("src/execute_token/.heredoc", ft_itoa(i)));
		free(heredoc_file_name);
		i++;
	}
	return ;
}

char	*make_cmd(t_token *list, t_execute *pack)
{
	char	**cmd_path;
	char	*cmd;
	char	*dangling;

	cmd_path = ft_split(get_env(pack->env_list, "PATH"), ':');
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
