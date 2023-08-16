/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:18:01 by shikim            #+#    #+#             */
/*   Updated: 2023/08/16 21:39:28 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_linked_list	*create_node(int data)
{
	t_linked_list	*new;

	new = (t_linked_list *)malloc(sizeof(t_linked_list));
	if (new == NULL)
		exit_program("fail to call system");
	new->fd = data;
	new->next = NULL;
	return (new);
}

t_linked_list	*insert_l_node(t_linked_list *head, int data)
{
	t_linked_list	*new_node;
	t_linked_list	*node;

	if (head == NULL)
	{
		new_node = create_node(data);
		return (new_node);
	}
	else
	{
		node = head;
		while (node->next != NULL)
			node = node->next;
		new_node = create_node(data);
		node->next = new_node;
		new_node->next = NULL;
	}
	return (head);
}

void	ctrl_exit_status_with_singal(int status)
{
	if (custom_wxd(status))
		g_exit_code = custom_wss(status);
	else if (custom_wgd(status))
		g_exit_code = custom_wsg(status) + 128;
}
