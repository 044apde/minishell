/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_envp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:54:53 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/20 20:44:40 by hyungjup         ###   ########.fr       */
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
	t_env_list	*tmp; // env_list의 포인터를 복사해둠

	tmp = *env_list;
	if (tmp == NULL)
	{
		*env_list = node; // env_list가 NULL이면 node를 넣어줌
		node->next = NULL;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
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
		if (!value_copy)
			return (NULL);
		*value_copy = '\0';
		node = create_env_node(ft_strdup(key_copy), ft_strdup(value_copy + 1));
		if (!node)
			return (NULL);
		add_env_node(&env_list, node);
		i++;
	}
	return (env_list);
}

// void	print_env_list(t_env_list *env_list)
// {
// 	while (env_list)
// 	{
// 		printf("%s=%s\n", env_list->key, env_list->value);
// 		env_list = env_list->next;
// 	}
// }

int main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	int			env_count;
	t_env_list	*env_list;

	env_list = NULL;
	env_count = 0;
	while (envp[env_count])
		env_count++;
	env_list = build_env_list(envp, env_count, env_list);
	if (!env_list)
		return (1);
	// print_env_list(env_list);
}


