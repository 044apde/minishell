/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:21:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/08 15:39:17 by hyungjup         ###   ########.fr       */
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

void	export_process(t_env_list *env_list, t_token *token_list)
{
	char	*key;
	char	*value;
	char	*equal_sign;

	while (token_list != NULL)
	{
		equal_sign = ft_strchr(token_list->token, '=');
		if (equal_sign != NULL)
		{
			key = ft_substr(token_list->token, 0, \
					equal_sign - token_list->token);
			value = ft_strdup(equal_sign + 1);
			token_list = token_list->next;
			while (token_list != NULL)
			{
				value = ft_strjoin(value, "");
				value = ft_strjoin(value, token_list->token);
				token_list = token_list->next;
			}
			add_update_env_list(env_list, key, value);
			free(key);
			free(value);
			key = NULL;
			break ;
		}
		token_list = token_list->next;
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
