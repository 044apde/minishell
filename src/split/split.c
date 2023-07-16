/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/16 14:30:19 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

void	make_word(char **arr, char *s, int count)
{
	int		st;
	int		e;
	int		i;

	st = 0;
	e = -1;
	i = 0;
	while (s[++e] != '\0')
	{
		if (s[e] == '|' && ++st)
			arr[i++] = ft_strdup("|");
		else if (s[e] == '<' && ++st)
			(make_redir_in(arr, s, e, i) == TRUE && (++i));
		else if (s[e] == '>' && ++st)
			(make_redir_out(arr, s, e, i) == TRUE && (++i));
		else if (s[e + 1] == '|' || s[e + 1] == '<' \
					|| s[e + 1] == '>' || s[e + 1] == '\0')
		{
			arr[i++] = ft_substr(s, st, e - st + 1);
			st = e + 1;
		}
	}
}

char	**split(char *s)
{
	char	**arr;
	int		count;

	count = count_word(s);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		exit(1);
	arr[count] = NULL;
	make_word(arr, s, count);
	trim_word(arr);
	return (arr);
}
