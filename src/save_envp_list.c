/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_envp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:54:53 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/21 21:41:53 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env_list	*create_env_node(char *key, char *value)
{
	t_env_list	*node;

	node = (t_env_list *)malloc(sizeof(t_env_list));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	add_env_node(t_env_list **env_list, t_env_list *node)
{
	t_env_list	*tmp;

	tmp = *env_list;
	if (tmp == NULL)
	{
		*env_list = node;
		node->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	return ;
}

t_env_list	*build_env_list(char **envp, int env_count, t_env_list *env_list)
{
	t_env_list	*node;
	char		*key_copy;
	char		*value_copy;
	int			i;

	i = 0;
	while (i < env_count)
	{
		key_copy = envp[i];
		value_copy = ft_strchr(key_copy, '=');
		if (value_copy == NULL)
			return (NULL);
		*value_copy = '\0';
		node = create_env_node(ft_strdup(key_copy), ft_strdup(value_copy + 1));
		if (node == NULL)
			return (NULL);
		add_env_node(&env_list, node);
		i++;
	}
	return (env_list);
}

t_env_list	*set_env(char **envp)
{
	t_env_list	*env_list;
	int			env_count;

	env_list = NULL;
	env_count = 0;
	while (envp[env_count])
		env_count++;
	env_list = build_env_list(envp, env_count, env_list);
	if (env_list == NULL)
		exit_program("failed to get env");
	return (NULL);
}

char	*get_env(t_env_list *env_list, char *str)
{
	while (env_list != NULL)
	{
		if (ft_strncmp(env_list->key, str + 1, ft_strlen(str)) == 0)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}
