/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:47:46 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/15 12:12:52 by hyungjup         ###   ########.fr       */
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

char	**create_envp_copy(int count)
{
	char	**envp_copy;

	envp_copy = (char **)malloc(sizeof(char *) * (count + 1));
	if (envp_copy == NULL)
		return (NULL);
	envp_copy[count] = NULL;
	return (envp_copy);
}

char	*create_single_envp_entry(t_env_list *env_list, char **envp_copy, int i)
{
	char	*tmp;

	tmp = ft_strjoin(env_list->key, "=");
	if (tmp == NULL)
	{
		free_envp(envp_copy);
		return (NULL);
	}
	envp_copy[i] = ft_strjoin(tmp, env_list->value);
	free(tmp);
	return (envp_copy[i]);
}

char	**env_list_to_envp(t_env_list *env_list, int count)
{
	char	**envp_copy;
	int		i;

	envp_copy = create_envp_copy(count);
	if (envp_copy == NULL)
		return (NULL);
	i = 0;
	while (env_list != NULL)
	{
		envp_copy[i] = create_single_envp_entry(env_list, envp_copy, i);
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
	char	*tmp;

	if (compare_str(str, "$?") == TRUE)
	{
		tmp = ft_itoa(g_exit_code);
		if (tmp)
			return (tmp);
		return (ft_itoa(g_exit_code));
	}
	while (env_list != NULL)
	{
		if (str[0] == '$')
		{
			++str;
			if (*str == '\0')
				return (--str);
		}
		if (compare_str(env_list->key, str) == TRUE)
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}
