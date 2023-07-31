/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:21:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/31 18:52:30 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	no_argv_print(t_env_list *env_list)
{
	t_env_list	*sorted_env_list;

	sorted_env_list = sorted_list(env_list);
	while (sorted_env_list != NULL)
	{
		if (sorted_env_list->value != NULL)
			printf("declare -x %s=\"%s\"\n", \
			sorted_env_list->key, sorted_env_list->value);
		else
			printf("declare -x %s\n", sorted_env_list->key);
		sorted_env_list = sorted_env_list->next;
	}
}

void	update_env_value(t_env_list *list, char *value)
{
	free(list->value);
	list->value = ft_strdup(value);
	return ;
}

void	add_update_env_list(t_env_list *env_list, char *key, char *value)
{
	t_env_list	*current;
	t_env_list	*new;
	t_env_list	*prev;

	current = env_list;
	prev = NULL;
	while (current != NULL)
	{
		if (compare_str(current->key, key) == TRUE)
		{
			update_env_value(current, value);
			return ;
		}
		prev = current;
		current = current->next;
	}
	new = (t_env_list *)malloc(sizeof(t_env_list));
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	new->next = NULL;
	if (prev != NULL)
		prev->next = new;
	else
		env_list = new;
	return ;
}

void	handle_token(t_env_list *env_list, t_token *token_list)
{
	char	**key_value;
	char	*key;
	char	*value;
}

void	ft_export(t_env_list *env_list, t_token *token_list)
{
	char		*key;
	char		*value;
	char		**key_value;
	char		*equal_sign;

	if (token_list->next == NULL)
	{
		no_argv_print(env_list);
		return ;
	}
	else
	{
		while (token_list != NULL)
		{
			equal_sign = ft_strchr(token_list->token, '=');
			if (equal_sign)
			{
				key = ft_substr(token_list->token, 0, equal_sign - token_list->token);
				if (*(equal_sign + 1) == '\0')
					value = ft_strdup("");
				else
					value = ft_strdup(equal_sign + 1);
				add_update_env_list(env_list, key, value);
				if (value)
					free(value);
				free(key);
				break ;
			}
			token_list = token_list->next;
		}
	}
	return ;
}
