/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:39:31 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 15:24:37 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*create_token(char *s)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		exit_program("failed to malloc");
	new->token = s;
	new->type = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_token	*insert_node(t_token *head, char *s)
{
	t_token	*node;
	t_token	*new;

	if (head == NULL)
	{
		head = create_token(NULL);
		return (head);
	}
	node = head;
	while (node->next != NULL)
		node = node->next;
	new = create_token(s);
	node->next = new;
	new->prev = node;
	return (head);
}

void	insert_string_node(t_token *head, char *s, int *start, int end)
{
	insert_node(head, ft_substr(s, *start, end - *start + 1));
	*start = end + 1;
	return ;
}

int	is_sep(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '\0' || c == ' '\
		|| c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}
