/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:21:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/15 21:08:26 by shikim           ###   ########.fr       */
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

void	enroll_only_key(t_token *t_list, t_env_list *env_list)
{
	char	*key;
	t_env_list *list;

	list = env_list;
	key = t_list->next->token;
	while (list != NULL)
	{
		if (compare_str(key, list->key) == TRUE)
			return ;
		list = list->next;
	}
	add_update_env_list(env_list, key, NULL);
	return ;
}

void	enroll_key_with_novalue(t_token *t_list, t_env_list *env_list)
{
	char	*key;
	t_env_list *list;

	list = env_list;
	key = t_list->next->token;
	while (list != NULL)
	{
		if (compare_str(key, list->key) == TRUE)
			return ;
		list = list->next;
	}
	printf("here\n");
	add_update_env_list(env_list, key, "");
	return ;
}

void	ft_export(t_env_list *env_list, t_token *token_list)
{
	if (token_list->next == NULL || is_operator2(token_list->next) == TRUE)
		no_argv_print(env_list);
	else if (ft_isalpha(token_list->next->token[0]) == FALSE)
		g_exit_code = 1;
	else if (ft_strchr(token_list->next->token, '=') == NULL)
		enroll_only_key(token_list, env_list);
	else if (*(ft_strchr(token_list->next->token, '=') + 1) == '\0')
	{
		if (token_list->next->type == D_QUOTE || token_list->next->type == S_QUOTE)
		{
			if (token_list->next->next != NULL && is_operator2(token_list->next) == FALSE)
				g_exit_code = 1;
			else
				export_process(env_list, token_list);
		}
		else if (token_list->next->next == NULL || is_operator2(token_list->next->next) == TRUE)
			enroll_key_with_novalue(token_list, env_list);
		else
			g_exit_code = 1;
	}
	else if (token_list->next->next == NULL)
		export_process(env_list, token_list);
	else if (is_operator2(token_list->next->next) == FALSE)
		g_exit_code = 1;
	else
		export_process(env_list, token_list);
}
