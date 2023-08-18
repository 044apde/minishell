/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:11:34 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/18 20:00:50 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	substitute_token(t_token *s_current, char *h_file_name, \
							char *input, int infile)
{
	free(s_current->next->token);
	s_current->next->token = h_file_name;
	free(input);
	close(infile);
}

int	process(t_token *o_current, t_token *s_current)
{
	int			infile;
	char		*input;
	char		*h_file_name;

	h_file_name = find_last_heredoc_name();
	infile = open(h_file_name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (infile == ERROR)
		return (126);
	while (TRUE)
	{
		input = readline("> ");
		if (input == NULL)
		{
			substitute_token(s_current, h_file_name, input, infile);
			return (TRUE);
		}
		if (compare_str(input, o_current->next->token) == TRUE)
			break ;
		write(infile, input, ft_strlen(input));
		write(infile, "\n", 1);
		free(input);
	}
	substitute_token(s_current, h_file_name, input, infile);
	return (TRUE);
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
			if (process(o_current, t_current) == 126)
			{
				ft_putstr_fd("ohmybash#", 2);
				ft_putstr_fd(" Can't open heredoc file\n", 2);
				g_exit_code = 126;
				return ;
			}
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
	heredoc_file_name = ft_strjoin("/tmp/.heredoc", tmp);
	free(tmp);
	while (access(heredoc_file_name, F_OK) == 0)
	{
		free(heredoc_file_name);
		heredoc_file_count++;
		tmp = ft_itoa(heredoc_file_count);
		heredoc_file_name = ft_strjoin("/tmp/.heredoc", tmp);
		free(tmp);
	}
	return (heredoc_file_name);
}
