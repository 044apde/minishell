/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:01:58 by shikim            #+#    #+#             */
/*   Updated: 2023/08/11 11:34:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token_pack	*init_token_pack(char *s, t_token *head)
{
	t_token_pack *token_pack;

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
	t_token_pack	*t_pack;

	t_pack = init_token_pack(s, split->head);
	while (s[++t_pack->end] != '\0')
	{
		if (s[t_pack->end] == '\'' | s[t_pack->end] == '\"')
			check_quote(t_pack);
		else if (s[t_pack->end] == ' ' && t_pack->prev_quote_type == 0 && ++t_pack->start)
			continue ;
		else if (s[t_pack->end] == '|' && t_pack->prev_quote_type == 0 && ++t_pack->start)
			insert_node(split->head, ft_strdup("|"));
		else if (s[t_pack->end] == '<' && t_pack->prev_quote_type == 0)
			make_redir_in(split->head, s, t_pack->start++);
		else if (s[t_pack->end] == '>' && t_pack->prev_quote_type == 0)
			make_redir_out(split->head, s, t_pack->start++);
		else if (is_sep(s[t_pack->end + 1]) == TRUE && t_pack->prev_quote_type == 0)
			insert_string_node(split->head, s, &t_pack->start, t_pack->end);
	}
	free(t_pack);
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
	return (split->head);
}
