/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:11:34 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/31 18:54:43 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void heredoc_process(t_token *token_list, t_execute *pack)
{
	t_token	*current;
	int		infile;
	char	*input;

	current = token_list;
	while (current != NULL)
	{
		if (current->type == HEREDOC)
		{
			infile = open("src/execute_token/.heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0777);
			while (1)
			{
				input = readline("> ");
				if (compare_str(input, current->next->token) == TRUE)
					break;
				write(infile, input, ft_strlen(input));
				write(infile, "\n", 1);
				free(input);
			}
			free(input);
			close(infile);
		}
		current = current->next;
	}
}

