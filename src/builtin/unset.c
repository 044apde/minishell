/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:52:14 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/20 22:33:30 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_unset(char **envp, t_env_list *env_list, char **argv)
{
	char		*str;
	int			i;
	t_env_list	*tmp;
	t_env_list	*prev;

	env_list = NULL;
	if (argv[1] == NULL)
		return (0);
	i = 1;
	while (argv[i])
	{
		tmp = env_list;
		prev = env_list;
		while (tmp)
		{
			if (ft_strncmp(tmp->key, argv[i], ft_strlen(tmp->key)) == 0)
			{
				free(tmp->key);
				if (tmp->value)
					free(tmp->value);
				if (prev != tmp)
					prev->next = tmp->next;
				else
					env_list = tmp->next;
				free(tmp);
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_env_list	*env_list;
	int			env_count;

	env_list = NULL;
	env_count = 0;
	env_list = build_env_list(envp, env_count, env_list);
	ft_unset(envp, env_list, argv);
	return (0);
}
