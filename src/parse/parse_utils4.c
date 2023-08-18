/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:52:44 by shikim            #+#    #+#             */
/*   Updated: 2023/08/18 21:28:07 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_d_index(char *token)
{
	int	index;

	index = -1;
	while (token[++index] != '\0')
	{
		if (token[index] == '$')
			return (index);
	}
	return (ERROR);
}

int	find_s_index(char *token, int d_index)
{
	int	index;

	index = d_index;
	while (token[++index] != '\0')
	{
		if (is_sep(token[index]) == TRUE)
			return (index);
	}
	if (token[index] == '\0')
		return (index);
	return (ERROR);
}

char	*make_sub(char *token, int d, int s, char *env_token)
{
	char	*new_token;
	char	*dangling;

	new_token = ft_substr(token, 0, d);
	dangling = new_token;
	new_token = ft_strjoin(new_token, env_token);
	free(dangling);
	free(env_token);
	dangling = new_token;
	env_token = ft_substr(token, s, ft_strlen(token) - d);
	new_token = ft_strjoin(new_token, env_token);
	free(env_token);
	free(dangling);
	return (new_token);
}

char	*make_substitute(char *token, t_env_list *env_list)
{
	char	*new_token;
	char	*env_token;
	int		d_index;
	int		s_index;

	d_index = find_d_index(token);
	s_index = find_s_index(token, d_index);
	if (s_index == ERROR || d_index == ERROR)
		return (NULL);
	new_token = ft_substr(token, d_index, s_index - d_index);
	if (compare_str(new_token, "$") == TRUE)
	{
		free(new_token);
		return (NULL);
	}
	env_token = get_env(env_list, new_token);
	if (env_token == NULL)
		env_token = ft_strdup("");
	free(new_token);
	new_token = make_sub(token, d_index, s_index, env_token);
	return (new_token);
}

void	free_env_list(t_env_list *env_list)
{
	t_env_list	*temp_node;
	char		**temp_envp;

	while (env_list != NULL)
	{
		temp_node = env_list;
		env_list = env_list->next;
		if (temp_node->envp_copy != NULL)
		{
			temp_envp = temp_node->envp_copy;
			while (*temp_envp != NULL)
			{
				free(*temp_envp);
				temp_envp++;
			}
			free(temp_node->envp_copy);
		}
		free(temp_node->key);
		free(temp_node->value);
		free(temp_node);
	}
	return ;
}
