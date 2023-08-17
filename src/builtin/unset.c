/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:52:14 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/17 17:58:21 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_valid_key(char *str, t_env_list *env_list)
{
	int			i;
	t_env_list	*list;

	if (str == NULL || ft_isdigit(str[0]) == TRUE)
		return (FALSE);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
			return (FALSE);
		i++;
	}
	list = env_list;
	while (list != NULL)
	{
		if (compare_str(list->key, str) == TRUE)
			return (TRUE);
		list = list->next;
	}
	return (FALSE);
}

t_env_list	*delete_env_node(t_env_list *env_list, char *str)
{
	t_env_list	*list;
	t_env_list	*prev;

	list = env_list;
	prev = NULL;
	while (list != NULL)
	{
		if (compare_str(list->key, str) == TRUE)
		{
			if (prev == NULL)
				env_list = list->next;
			else
				prev->next = list->next;
			free(list->key);
			free(list->value);
			free(list);
			return (env_list);
		}
		prev = list;
		list = list->next;
	}
	return (env_list);
}

void	ft_unset(t_env_list *env_list, t_token *token_list)
{
	t_token	*list;

	list = token_list;
	if (list->next == NULL)
	{
		ft_putstr_fd("\033[0;31mohmybash# Not enough arguments\033[0;0m\n", 2);
		g_exit_code = 1;
		return ;
	}
	else
	{
		while (list->next != NULL && list->next->type == WORD)
		{
			if (is_valid_key(list->next->token, env_list) == TRUE)
				env_list = delete_env_node(env_list, list->next->token);
			else
				return ;
			list = list->next;
		}
	}
	g_exit_code = 0;
	return ;
}
