/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:39:31 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 19:56:21 by shikim           ###   ########.fr       */
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
	return (head);
}

void	insert_string_node(t_token *head, char *s, int *st, int e)
{
	insert_node(head, ft_substr(s, *st, e - *st + 1));
	*st = e + 1;
	return ;
}

void	show_token(t_token *head)
{
	t_token	*node;

	node = head->next;
	printf("\033[0;34m===============================================\n");
	while (node != NULL)
	{
		printf("[%s]:%d ", node->token, node->type);
		node = node->next;
	}
	node = head->next;
	printf("\n===============================================\033[0;0m\n");
	return ;
}

int	is_sep(char c)
{
	if (c == '|' || c == '<' || c == '>' || c == '\0' || c == ' '\
		|| c == '\'' || c == '"')
		return (TRUE);
	return (FALSE);
}
