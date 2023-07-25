/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:18:37 by shikim            #+#    #+#             */
/*   Updated: 2023/07/25 16:46:45 by hyungjup         ###   ########.fr       */
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
		if (compare_str(input, limiter) == TRUE)
			break;
		write(infile, input, ft_strlen(input));
		write(infile, "\n", 1);
	}
	return ;
}

void	remvove_heredoc_file(void)
{
	int	heredoc;

	heredoc = open("src/execute_token/.heredoc", O_CREAT | O_RDWR | O_TRUNC);
	write(heredoc, "", 1);
	close(heredoc);
	return ;
}