/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:09:09 by shikim            #+#    #+#             */
/*   Updated: 2023/07/19 20:15:26 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	make_redir_in(t_token *head, char *s, int st)
{
	static int	redir_in;

	printf("now: %c next: %c\n", s[st], s[st + 1]);
	if (s[st + 1] != '<')
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			insert_node(head, "<<");
			return ;
		}
		redir_in = 0;
		insert_node(head, "<");
	}
	else
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			insert_node(head, "<<");
			return ;
		}
		redir_in = 1;
		return ;
	}
}

void	make_redir_out(t_token *head, char *s, int st)
{
	static int	redir_out;

	if (s[st + 1] != '>')
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			insert_node(head, ">>");
			return ;
		}
		redir_out = 0;
		insert_node(head, ">");
	}
	else
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			insert_node(head, ">>");
			return ;
		}
		redir_out = 1;
		return ;
	}
}

void	trim_word(char **arr)
{
	int		i;
	char	*dangling;

	i = -1;
	while (arr[++i] != NULL)
	{
		dangling = arr[i];
		arr[i] = ft_strtrim(arr[i], " ");
		free(dangling);
	}
	return ;
}
