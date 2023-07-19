/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/19 20:58:05 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*make_token(char *s)
{
	t_token	*head;
	int		e;
	int		st;

	head = insert_node(NULL, NULL);
	e = -1;
	st = 0;
	while (s[++e] != '\0')
	{
		if (s[e] == ' ' && ++st)
			continue ;
		else if (s[e] == '|' && ++st)
			insert_node(head, ft_strdup("|"));
		else if (s[e] == '<')
			make_redir_in(head, s, st++);
		else if (s[e] == '>')
			make_redir_out(head, s, st++);
		else if (s[e + 1] == '|' || s[e + 1] == '<' || s[e + 1] == '>' \
					|| s[e + 1] == '\0' || s[e + 1] == ' ')
		{
			insert_node(head, ft_substr(s, st, e - st + 1));
			st = e + 1;
		}
	}
	return (head);
}

char	**split(char *s)
{
	t_token	*head;

	head = make_token(s);
	show_token(head);
	return (NULL);
}
