/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/08/03 16:51:25 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	do_heredoc(t_token *list, t_execute *pack, int infile)
{
	char	*limiter;
	char	*input;

	limiter = list->next->token;
	while (TRUE)
	{
		input = readline("\033[0;32m>\033[0m ");
		if (input == NULL || compare_str(input, limiter) == TRUE)
		{
			free(input);
			break ;
		}
		write(infile, input, ft_strlen(input));
		write(infile, "\n", 1);
		free(input);
	}
	return ;
}

void	remove_heredoc_file(void)
{
	int			i;
	char		*heredoc_file_name;
	static int	here_doc_file_count;

	i = 0;
	while (i < here_doc_file_count)
	{
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", ft_itoa(i));
		if (access(heredoc_file_name, F_OK) < 0)
			break ;
		unlink(heredoc_file_name);
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