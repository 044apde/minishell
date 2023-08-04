/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:22:22 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/03 20:38:51 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	compare_keys(t_env_list *a, t_env_list *b)
{
	return (ft_strcmp(a->key, b->key));
}

void	swap_env_nodes(t_env_list *a, t_env_list *b)
{
	char	*temp_key;
	char	*temp_value;

	temp_key = a->key;
	temp_value = a->value;
	a->key = b->key;
	a->value = b->value;
	b->key = temp_key;
	b->value = temp_value;
}

t_env_list	*create_new_node(t_env_list *list)
{
	t_env_list	*new;

	new = (t_env_list *)malloc(sizeof(t_env_list));
	new->key = ft_strdup(list->key);
	if (list->value != NULL)
		new->value = ft_strdup(list->value);
	else
		new->value = "";
	new->next = NULL;
	return (new);
}

t_env_list	*sort_env_list(t_env_list *env_list)
{
	t_env_list	*i;
	t_env_list	*j;

	i = env_list;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (compare_keys(i, j) > 0)
				swap_env_nodes(i, j);
			j = j->next;
		}
		i = i->next;
	}
	return (env_list);
}
