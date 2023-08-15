/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:34:53 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/15 15:49:12 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env_list	*copy_env_list(t_env_list *env_list)
{
	t_env_list	*copy;
	t_env_list	*current;
	t_env_list	*new;

	copy = NULL;
	current = env_list;
	while (current != NULL)
	{
		new = create_new_node(current);
		new->next = copy;
		copy = new;
		current = current->next;
	}
	return (copy);
}

t_env_list	*sorted_list(t_env_list *env_list)
{
	t_env_list	*sorted_list;

	sorted_list = copy_env_list(env_list);
	sorted_list = sort_env_list(sorted_list);
	return (sorted_list);
}

void	update_env_value(t_env_list *list, char *value)
{
	free(list->value);
	list->value = ft_strdup(value);
	return ;
}

t_env_list	*find_update(t_env_list *current, char *key, char *value)
{
	t_env_list	*prev;

	while (current != NULL)
	{
		if (compare_str(current->key, key) == TRUE)
		{
			update_env_value(current, value);
			return (NULL);
		}
		prev = current;
		current = current->next;
	}
	return (prev);
}

void	add_update_env_list(t_env_list *env_list, char *key, char *value)
{
	t_env_list	*current;
	t_env_list	*new;
	t_env_list	*prev;

	current = env_list;
	prev = find_update(current, key, value);
	if (prev == NULL)
		return ;
	new = (t_env_list *)malloc(sizeof(t_env_list));
	if (new == NULL)
		return ;
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (prev != NULL)
		prev->next = new;
	else
		env_list = new;
	return ;
}
