/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/08/14 20:06:59 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token_pack	*init_token_pack(char *s, t_token *head)
{
	t_token_pack	*token_pack;

	token_pack = (t_token_pack *)malloc(sizeof(t_token_pack));
	if (token_pack == NULL)
	{
		printf("\033[0;31mError: failed to system call\033[0;0m\n");
		exit(1);
	}
	token_pack->s = s;
	token_pack->start = 0;
	token_pack->end = -1;
	token_pack->prev_quote_type = 0;
	token_pack->head = head;
	return (token_pack);
}

t_split	*make_token(char *s, t_split *split)
{
	t_token_pack	*p;

	p = init_token_pack(s, split->head);
	while (s[++p->end] != '\0')
	{
		if (s[p->end] == '\'' | s[p->end] == '\"')
			check_quote(p);
		else if (s[p->end] == ' ' && p->prev_quote_type == 0 && ++p->start)
			continue ;
		else if (s[p->end] == '|' && p->prev_quote_type == 0 && ++p->start)
			insert_node(split->head, ft_strdup("|"));
		else if (s[p->end] == '<' && p->prev_quote_type == 0)
			make_redir_in(split->head, s, p->start++);
		else if (s[p->end] == '>' && p->prev_quote_type == 0)
			make_redir_out(split->head, s, p->start++);
		else if (is_sep(s[p->end + 1]) == TRUE && p->prev_quote_type == 0)
			insert_string_node(split->head, s, &p->start, p->end);
	}
	free(p);
	return (split);
}

t_token	*split(char *s)
{
	t_split	*split;
	t_token	*tmp;

	split = (t_split *)malloc(sizeof(t_split));
	split->head = insert_node(NULL, NULL);
	split = make_token(s, split);
	if (split->status == TRUE)
		exit_program("check quotation");
	tmp = split->head;
	free(split);
	return (split->head);
}
