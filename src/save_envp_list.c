/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_envp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:54:53 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/20 13:57:37 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_env_list(char **envp, t_env_list *env_list)
{
	int		env_count;
	int		i;
	char	**env_list; // 이 부분은 구조체로 바꿔서 갖고 다니기

	env_count = 0;
	while (envp[env_count])
		env_count++;
	i = 0;
	env_list->env = (char **)malloc(sizeof(char *) * (env_count + 1));
	if (!env_list->env)
		return (1);
	while (i < env_count)
	{
		env_list->env[i] = (char *)malloc(sizeof(char) * (ft_strlen(envp[i]) + 1));
		if (!env_list->env[i])
		{
			i = 0;
			while (i < env_count)
				free(env_list->env[i++]);
			return (1);
		}
		ft_strlcpy(env_list->env[i], envp[i], ft_strlen(envp[i]) + 1);
		i++;
	}
	env_list->env[i] = NULL;
	return (0);
}
