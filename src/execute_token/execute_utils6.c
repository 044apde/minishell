/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:11:34 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/03 14:59:53 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	process(t_token *current, t_execute *pack)
{
	int			infile;
	char		*input;
	char		*heredoc_file_name;

	heredoc_file_name = find_last_heredoc_name(current);
	infile = open(heredoc_file_name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	while (1)
	{
		input = readline("> ");
		if (compare_str(input, current->next->token) == TRUE)
			break ;
		write(infile, input, ft_strlen(input));
		write(infile, "\n", 1);
		free(input);
	}
	current->next->token = heredoc_file_name;
	free(input);
	close(infile);
	return ;
}

void	heredoc_process(t_token *token_list, t_execute *pack)
{
	t_token	*current;
	int		heredoc_pid;

	current = token_list;
	while (current != NULL)
	{
		if (current->type == HEREDOC)
			process(current, pack);
		current = current->next;
	}
}

char	**make_heredoc_option(t_token *cmd_node, t_execute *pack)
{
	char	**cmd_option;

	cmd_option = (char **)malloc(sizeof(char *) * 2);
	if (cmd_option == NULL)
		return (NULL);
	cmd_option[1] = NULL;
	cmd_option[0] = ft_strdup("/bin/cat");
	return (cmd_option);
}

char	*find_last_heredoc_name(t_token *token_list)
{
	static int	heredoc_file_count;
	char		*heredoc_file_name;

	heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", \
						ft_itoa(heredoc_file_count));
	while (access(heredoc_file_name, F_OK) == 0)
	{
		heredoc_file_count++;
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", \
							ft_itoa(heredoc_file_count));
	}
	return (heredoc_file_name);
}
