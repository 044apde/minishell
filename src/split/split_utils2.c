/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:09:09 by shikim            #+#    #+#             */
/*   Updated: 2023/07/16 14:31:35 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	make_redir_in(char **arr, char *s, int st, int i)
{
	static int	redir_in;

	if (s[st + 1] != '<')
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			arr[i] = ft_strdup("<<");
			return (TRUE);
		}
		redir_in = 0;
		arr[i] = ft_strdup("<");
		return (TRUE);
	}
	else
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			arr[i] = ft_strdup("<<");
			return (TRUE);
		}
		redir_in = 1;
		return (FALSE);
	}
}

int	make_redir_out(char **arr, char *s, int st, int i)
{
	static int	redir_out;

	if (s[st + 1] != '>')
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			arr[i] = ft_strdup(">>");
			return (TRUE);
		}
		redir_out = 0;
		arr[i] = ft_strdup(">");
		return (TRUE);
	}
	else
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			arr[i] = ft_strdup(">>");
			return (TRUE);
		}
		redir_out = 1;
		return (FALSE);
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

void	show_token(char **arr)
{
	int	i;

	i = 0;
	printf("\033[0;34m================ THE TOKEN ================\n");
	while (arr[i] != NULL)
	{
		printf("[%s] ", arr[i]);
		++i;
	}
	printf("\n================ END TOKEN ================\033[0;0m\n");
	return ;
}
