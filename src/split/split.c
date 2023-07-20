/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/07/20 15:43:59 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_split	*make_token(char *s, t_split *split)
{
	int		e;
	int		st;

	e = -1;
	st = 0;
	while (s[++e] != '\0')
	{
		split->status = check_quote(s[e]);
		if (split->status == TRUE)
			continue ;
		else if (split->status == DONE)
			insert_string_node(split->head, s, &st, e);
		else if (s[e] == ' ' && ++st)
			continue ;
		else if (s[e] == '|' && ++st)
			insert_node(split->head, ft_strdup("|"));
		else if (s[e] == '<')
			make_redir_in(split->head, s, st++);
		else if (s[e] == '>')
			make_redir_out(split->head, s, st++);
		else if (is_sep(s[e + 1]) == TRUE)
			insert_string_node(split->head, s, &st, e);
	}
	return (split);
}

t_token	*split(char *s)
{
	t_split	*split;

	split = (t_split *)malloc(sizeof(t_split));
	split->head = insert_node(NULL, NULL);
	split = make_token(s, split);
	if (split->status == TRUE)
		exit_program("check quotation");
	show_token(split->head);
	return (split->head);
}
