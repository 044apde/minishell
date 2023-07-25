/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:47:46 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/25 17:48:06 by hyungjup         ###   ########.fr       */
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

char	**env_list_to_envp(t_env_list *env_list, char **envp, int count)
{
	char		**envp_copy;
	t_env_list	*tmp;
	int			i;

	envp_copy = (char **)malloc(sizeof(char *) * (count + 1));
	envp_copy[count] = NULL;
	i = 0;
	while (env_list != NULL)
	{
		envp_copy[i] = ft_strjoin(ft_strjoin(env_list->key, "="), env_list->value);
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
