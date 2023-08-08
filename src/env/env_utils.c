/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:47:46 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/08 20:03:28 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_envp(char **envp_copy)
{
	int	i;

	i = 0;
	while (envp_copy[i] != NULL)
	{
		free(envp_copy[i]);
		i++;
	}
	free(envp_copy);
	return ;
}

char	**env_list_to_envp(t_env_list *env_list, int count)
{
	char	**envp_copy;
	int		i;

	envp_copy = (char **)malloc(sizeof(char *) * (count + 1));
	envp_copy[count] = NULL;
	i = 0;
	while (env_list != NULL)
	{
		envp_copy[i] = ft_strjoin(ft_strjoin(env_list->key, "="), \
		env_list->value);
		if (envp_copy[i] == NULL)
		{
			free_envp(envp_copy);
			return (NULL);
		}
		env_list = env_list->next;
		i++;
	}
	envp_copy[i] = NULL;
	return (envp_copy);
}

char	*get_env(t_env_list *env_list, char *str)
{
	while (env_list != NULL)
	{
		if (str[0] == '$')
		{
			++str;
			if (*str == '\0')
				return (--str);
		}
		if (compare_str(env_list->key, str) == TRUE)
		{
			return (env_list->value);
		}
		env_list = env_list->next;
	}
	return (NULL);
}
