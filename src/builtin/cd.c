/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:41:59 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/09 16:25:05 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*get_env_value(char *key, t_env_list *env_list)
{
	t_env_list	*list;

	list = env_list;
	while (list != NULL)
	{
		if (ft_strncmp(list->key, key, ft_strlen(key)) == 0)
			return (list->value);
		list = list->next;
	}
	return (NULL);
}

void	ft_cd(t_env_list *env_list, t_token *token_list)
{
	if (token_list->next == NULL)
		chdir(get_env_value("HOME", env_list));
	else if (token_list->next->next == NULL)
	{
		if (chdir(token_list->next->token) == -1)
		{
			printf("cd: %s: No such file or directory\n", \
				token_list->next->token);
			exit(1);
		}
		
	}
	exit(0);
	return ;
}
