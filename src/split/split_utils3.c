/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:55:04 by shikim            #+#    #+#             */
/*   Updated: 2023/07/20 14:40:37 by shikim           ###   ########.fr       */
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

int	check_quote(char c)
{
	int			check1;
	int			check2;
	static int	owner;

	check1 = check_quote1(c);
	check2 = check_quote2(c);
	if (owner == 0)
	{
		if ((check1 >= TRUE) && ++owner)
			return (check1);
		else if (check2 >= TRUE)
		{
			owner = 2;
			return (check2);
		}
	}
	else if (owner == 1)
	{
		if (check1 == DONE)
			owner = 0;
		return (check1);
	}
	if (check2 == DONE)
		owner = 0;
	return (check2);
}
