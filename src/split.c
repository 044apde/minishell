/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/14 21:14:44 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ctrl_string(int *count, int *is_sep)
{
	if (*is_sep == FALSE)
	{
		*count = *count + 1;
		*is_sep = TRUE;
	}
	return ;
}

void	ctrl_redir_out(int *count, int *is_sep, char c, char next_c)
{
	static int	redir_out;

	ctrl_string(count, is_sep);
	if (c == '>' && next_c != '>')
	{
		redir_out = 0;
		*count += 1;
	}
	else if (c == '>' && next_c == '>')
	{
		if (redir_out == 1)
		{
			write(1, "2", 1);
			redir_out = 0;
			*count += 1;
		}
		else
			redir_out = 1;
	}
}

void	ctrl_redir_in(int *count, int *is_sep, char c, char next_c)
{
	static int	redir_in;

	ctrl_string(count, is_sep);
	if (c == '<' && next_c != '<')
	{
		redir_in = 0;
		*count += 1;
	}
	else if (c == '<' && next_c == '<')
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			*count += 1;
		}
		else
			redir_in = 1;
	}
}

int	count_word(char *s)
{
	int	i;
	int	count;
	int	is_sep;

	i = -1;
	count = 0;
	is_sep = TRUE;
	while (s[++i] != '\0')
	{
		if (s[i] == '|' && ++count > 0)
			ctrl_string(&count, &is_sep);
		else if (s[i] == '>')
			ctrl_redir_out(&count, &is_sep, s[i], s[i + 1]);
		else if (s[i] == '<')
			ctrl_redir_in(&count, &is_sep, s[i], s[i + 1]);
		else
			is_sep = FALSE;
	}
	if (is_sep == FALSE)
		++count;
	return (count);
}

char	**split(char *s)
{
	char	**arr;
	int		count;

	count = count_word(s);
	printf("count: %d\n", count);
	return (arr);
}
