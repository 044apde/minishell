/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:21:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/15 15:42:50 by shikim           ###   ########.fr       */
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

t_token	*join_export(t_token *t_list, char *value)
{
	char	*tmp;

	while (t_list != NULL)
	{
		tmp = value;
		value = ft_strjoin(value, "");
		free(tmp);
		tmp = value;
		value = ft_strjoin(value, t_list->token);
		free(tmp);
		t_list = t_list->next;
	}
	return (t_list);
}

void	export_process(t_env_list *env_list, t_token *t_list)
{
	char	*key;
	char	*value;
	char	*equal_sign;

	while (t_list != NULL)
	{
		equal_sign = ft_strchr(t_list->token, '=');
		if (equal_sign != NULL)
		{
			key = ft_substr(t_list->token, 0, equal_sign - t_list->token);
			value = ft_strdup(equal_sign + 1);
			t_list = t_list->next;
			t_list = join_export(t_list, value);
			add_update_env_list(env_list, key, value);
			free(key);
			free(value);
			key = NULL;
			break ;
		}
		t_list = t_list->next;
	}
}

void	ft_export(t_env_list *env_list, t_token *token_list)
{
	if (token_list->next == NULL)
	{
		no_argv_print(env_list);
		return ;
	}
	else
		export_process(env_list, token_list->next);
	g_exit_code = 0;
	return ;
}
