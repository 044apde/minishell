/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:48:28 by shikim            #+#    #+#             */
/*   Updated: 2023/08/16 17:47:01 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
	char		*key;
	t_env_list	*list;

	list = env_list;
	key = t_list->next->token;
	if (t_list->next->next != NULL && is_operator2(t_list->next->next) == FALSE)
		error_export();
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
	int		i;

	i = 0;
	while (t_list->next->token[i] != '=')
		++i;
	key = ft_substr(t_list->next->token, 0, i);
	add_update_env_list(env_list, key, "");
	free(key);
}

void	error_export(void)
{
	ft_putstr_fd("\033[0;31mohmybash: export ", 2);
	ft_putstr_fd(":not a valid identifier\033[0;0m\n", 2);
	g_exit_code = 1;
	return ;
}

void	ctrl_after_equal(t_env_list *env_list, t_token *token_list)
{
	if (token_list->next->next == NULL || \
				is_operator2(token_list->next->next) == TRUE)
		enroll_key_with_novalue(token_list, env_list);
	else if (token_list->next->next->next != NULL && \
				is_operator2(token_list->next->next->next) == FALSE)
		error_export();
	else if (token_list->next->next->type == D_QUOTE \
				|| token_list->next->next->type == S_QUOTE)
	{
		if (token_list->next->next != NULL \
				&& is_operator2(token_list->next) == FALSE)
			export_process(env_list, token_list);
		else
			g_exit_code = 1;
	}
	else
		error_export();
	return ;
}
