/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/14 22:43:08 by shikim           ###   ########.fr       */
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
	int	i;
	int	st;
	int	is_sep;

	i = -1;
	st = 0;
	is_sep = TRUE;

	while (count > 0)
	{
		while (s[++i] != '\0')
		{
			if (s[i] == '|')
			{
				if (st != i)
				{
					make_stirng(arr, s, &st, i);
					printf("%s st:%d\n",*arr, st);
					++arr;
				}
				*arr = ft_strdup("|");
				if (*arr == NULL)
					exit(1);
				++st;
				printf("%s st:%d\n", *arr, st);
				++arr;
			}
			else
			{
			}
		}
		count--;
	}
	return ;
}

char	**split(char *s)
{
	char	**arr;
	int		count;

	count = count_word(s);
	printf("word_count: %d\n", count);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		exit(1);
	arr[count] = NULL;
	make_word(arr, s, count);
	return (arr);
}
