/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:41:12 by shikim            #+#    #+#             */
/*   Updated: 2023/08/12 17:26:33 by shikim           ###   ########.fr       */
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
		{
			if (count_double_quote == 0)
				++count_double_quote;
			else
				count_double_quote = 0;
		}
		else if (input[index] == '\'' && count_double_quote == 0)
		{
			if (count_single_quote == 0)
				++count_single_quote;
			else
				count_single_quote = 0;
		}
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
