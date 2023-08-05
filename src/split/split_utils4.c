/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:15:08 by shikim            #+#    #+#             */
/*   Updated: 2023/08/05 19:23:47 by shikim           ###   ########.fr       */
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

void	check_quote(t_token_pack *t_pack)
{
	if (t_pack->s[t_pack->end] == '\'')
	{
		if (t_pack->prev_quote_type == 0)
			t_pack->prev_quote_type = 1;
		else if (t_pack->prev_quote_type == 1)
		{
			make_quoted_string(t_pack->head, t_pack->s, &t_pack->start, t_pack->end);
			t_pack->prev_quote_type = 0;
		}
	}
	else if(t_pack->s[t_pack->end] == '\"')
	{
		if (t_pack->prev_quote_type == 0)
			t_pack->prev_quote_type = 2;
		else if (t_pack->prev_quote_type == 2)
		{
			make_quoted_string(t_pack->head, t_pack->s, &t_pack->start, t_pack->end);
			t_pack->prev_quote_type = 0;
		}
	}
	return ;
}
