/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:55:04 by shikim            #+#    #+#             */
/*   Updated: 2023/08/05 19:03:38 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_list(t_token *head)
{
	t_token	*node;
	t_token	*temp;

	node = head;
	while (node != NULL)
	{
		temp = node;
		node = node->next;
		if (temp->token != NULL)
			free(temp->token);
		free(temp);
	}
}

void	trim_word(char **arr)
{
	int		i;
	char	*dangling;

	i = -1;
	while (arr[++i] != NULL)
	{
		dangling = arr[i];
		arr[i] = ft_strtrim(arr[i], " ");
		free(dangling);
	}
	return ;
}
