/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 21:39:31 by shikim            #+#    #+#             */
/*   Updated: 2023/07/19 20:57:13 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*create_token(char *s)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		exit_program();
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

void	show_token(t_token *head)
{
	t_token	*node;

	node = head->next;
	printf("\033[0;34m===============================================\n");
	while (node != NULL)
	{
		printf("[%s] ", node->token);
		node = node->next;
	}
	printf("\n===============================================\033[0;0m\n");
	return ;
}
