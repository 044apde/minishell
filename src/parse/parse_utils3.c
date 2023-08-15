/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:41:12 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 12:19:35 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_node(t_token *head)
{
	int		count;
	t_token	*node;

	count = 0;
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

int	count_quote(int count_quote)
{
	if (count_quote == 0)
		return (++count_quote);
	else
		return (0);
}

int	pre_check_quote(char *input)
{
	int	index;
	int	count_single_quote;
	int	count_double_quote;

	index = -1;
	count_single_quote = 0;
	count_double_quote = 0;
	while (input[++index] != '\0')
	{
		if (input[index] == '"' && count_single_quote == 0)
			count_double_quote = count_quote(count_double_quote);
		else if (input[index] == '\'' && count_double_quote == 0)
			count_single_quote = count_quote(count_single_quote);
	}
	if (count_single_quote == 1 || count_double_quote == 1)
	{
		printf("\033[0;31mError: check quote\033[0;0m\n");
		return (ERROR);
	}
	return (TRUE);
}

void	free_token_list(t_token *list)
{
	t_token	*temp_node;

	while (list != NULL)
	{
		temp_node = list;
		list = list->next;
		if (temp_node != NULL)
			free(temp_node->token);
		free(temp_node);
	}
	return ;
}
