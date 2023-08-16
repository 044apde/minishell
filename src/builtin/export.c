/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:21:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/16 15:02:32 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	no_argv_print(t_env_list *env_list)
{
	t_env_list	*sorted_env_list;
	t_env_list	*origin_copy_sorted_list;
	t_env_list	*tmp_node;

	sorted_env_list = sorted_list(env_list);
	origin_copy_sorted_list = sorted_env_list;
	while (sorted_env_list != NULL)
	{
		if (sorted_env_list->value != NULL)
			printf("declare -x %s=\"%s\"\n", \
					sorted_env_list->key, sorted_env_list->value);
		else
			printf("declare -x %s\n", sorted_env_list->key);
		sorted_env_list = sorted_env_list->next;
	}
	while (origin_copy_sorted_list != NULL)
	{
		tmp_node = origin_copy_sorted_list;
		origin_copy_sorted_list = origin_copy_sorted_list->next;
		free(tmp_node->key);
		if (tmp_node->value != NULL)
			free(tmp_node->value);
		free(tmp_node);
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

void	ft_export(t_env_list *env_list, t_token *token_list)
{
	if (token_list->next == NULL || is_operator2(token_list->next) == TRUE)
		no_argv_print(env_list);
	else if (ft_isalpha(token_list->next->token[0]) == FALSE)
		error_export();
	else if (ft_strchr(token_list->next->token, '=') == NULL)
		enroll_only_key(token_list, env_list);
	else if (*(ft_strchr(token_list->next->token, '=') + 1) == '\0')
		ctrl_after_equal(env_list, token_list);
	else if (token_list->next->next == NULL)
		export_process(env_list, token_list);
	else if (is_operator2(token_list->next->next) == FALSE)
		error_export();
	else
		export_process(env_list, token_list);
}
