/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:15:08 by shikim            #+#    #+#             */
/*   Updated: 2023/08/12 17:27:36 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	make_quoted_string(t_token *head, char *s, int *start, int end)
{
	char	*quoted_string;

	quoted_string = ft_substr(s, *start, end - *start + 1);
	*start = end + 1;
	insert_node(head, quoted_string);
}

void	check_quote(t_token_pack *t_p)
{
	if (t_p->s[t_p->end] == '\'')
	{
		if (t_p->prev_quote_type == 0)
		{
			t_p->prev_quote_type = 1;
		}
		else if (t_p->prev_quote_type == 1)
		{
			make_quoted_string(t_p->head, t_p->s, &t_p->start, t_p->end);
			t_p->prev_quote_type = 0;
		}
	}
	else if (t_p->s[t_p->end] == '\"')
	{
		if (t_p->prev_quote_type == 0)
			t_p->prev_quote_type = 2;
		else if (t_p->prev_quote_type == 2)
		{
			make_quoted_string(t_p->head, t_p->s, &t_p->start, t_p->end);
			t_p->prev_quote_type = 0;
		}
	}
	return ;
}
