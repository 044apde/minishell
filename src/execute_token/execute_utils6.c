/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:11:34 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/15 14:33:43 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	process(t_token *o_current, t_token *s_current)
{
	int			infile;
	char		*input;
	char		*heredoc_file_name;

	heredoc_file_name = find_last_heredoc_name();
	infile = open(heredoc_file_name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	printf("infile name: %s\n", heredoc_file_name);
	if (infile == ERROR)
	{
		printf("\033[0;35mohmybash#: %s: can't open file\033[0;0m\n", \
				heredoc_file_name);
		exit(126);
	}
	while (TRUE)
	{
		input = readline("> ");
		if (input == NULL)
		{
			free(s_current->next->token);
			s_current->next->token = heredoc_file_name;
			free(input);
			close(infile);
			return ;
		}
		if (compare_str(input, o_current->next->token) == TRUE)
			break ;
		write(infile, input, ft_strlen(input));
		write(infile, "\n", 1);
		free(input);
	}
	free(s_current->next->token);
	s_current->next->token = heredoc_file_name;
	free(input);
	close(infile);
	return ;
}

void	heredoc_process(t_token *origin_list, t_token *token_list)
{
	t_token	*o_current;
	t_token	*t_current;

	o_current = origin_list;
	t_current = token_list;
	while (o_current != NULL && t_current != NULL)
	{
		if (o_current->type == HEREDOC)
		{
			process(o_current, t_current);
		}
		o_current = o_current->next;
		t_current = t_current->next;
	}
}

char	**make_heredoc_option(void)
{
	char	**cmd_option;

	cmd_option = (char **)malloc(sizeof(char *) * 2);
	if (cmd_option == NULL)
		return (NULL);
	cmd_option[1] = NULL;
	cmd_option[0] = ft_strdup("/bin/cat");
	return (cmd_option);
}

char	*find_last_heredoc_name(void)
{
	static int	heredoc_file_count;
	char		*heredoc_file_name;
	char		*tmp;

	heredoc_file_count = 0;
	tmp = ft_itoa(++heredoc_file_count);
	heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", tmp);
	free(tmp);
	while (access(heredoc_file_name, F_OK) == 0)
	{
		free(heredoc_file_name);
		heredoc_file_count++;
		tmp = ft_itoa(heredoc_file_count);
		heredoc_file_name = ft_strjoin("src/execute_token/.heredoc", tmp);
		free(tmp);
	}
	return (heredoc_file_name);
}
