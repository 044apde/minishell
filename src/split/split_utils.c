/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:39:31 by shikim            #+#    #+#             */
/*   Updated: 2023/07/14 22:38:59 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	make_stirng(char **arr, char *s, int *st, int end)
{
	char	*temp;

	temp = ft_strdup(s);
	temp[end + 1] = '\0';
	*arr = ft_substr(temp, *st, end - *st);
	free (temp);
	if (*arr == NULL)
		exit(1);
	*st = end;
	return ;
}
