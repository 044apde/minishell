/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/14 21:42:52 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		exit(1);
	return (arr);
}
