/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:41:12 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 19:52:31 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_node(t_token *head)
{
	int		count;
	t_token	*node;
	
	count =  0;
	node = head->next;
	while (node != NULL)
	{
		node = node->next;
		++count;
	}
	return (count);
}

char	**make_arr(t_token *node)
{
	int		i;
	char	**arr;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (count_node(node) + 1));
	if (arr == NULL)
		exit_program("failed to malloc");
	arr[count_node(node)] = NULL;
	node = node->next;
	while (node != NULL)
	{
		arr[i] = node->token;
		node = node->next;
		++i;
	}
	return (arr);
}

t_node	*make_tree(t_token *node)
{
	char	**arr;
	int		i;
	int		j;

	arr = make_arr(node);
	i = 0;
	j = 0;
	while (arr[i] != NULL)
	{
		if (compare_str(arr[i], "|") == TRUE)
		{
			while (j < i)
			{
				
			}
		}
	}
	return (NULL);
}
