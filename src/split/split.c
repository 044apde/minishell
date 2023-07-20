/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/20 14:38:05 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*make_token(char *s, t_token *head)
{
	int		e;
	int		st;
	int		check;

	e = -1;
	st = 0;
	while (s[++e] != '\0')
	{
		check = check_quote(s[e]);
		if (check == TRUE)
			continue ;
		else if (check == DONE)
			insert_string_node(head, s, &st, e);
		else if (s[e] == ' ' && ++st)
			continue ;
		else if (s[e] == '|' && ++st)
			insert_node(head, ft_strdup("|"));
		else if (s[e] == '<')
			make_redir_in(head, s, st++);
		else if (s[e] == '>')
			make_redir_out(head, s, st++);
		else if (is_sep(s[e + 1]) == TRUE)
			insert_string_node(head, s, &st, e);
	}
	return (head);
}

char	**split(char *s)
{
	t_token	*head;

	head = insert_node(NULL, NULL);
	head = make_token(s, head);
	show_token(head);
	free_list(head);
	return (NULL);
}
