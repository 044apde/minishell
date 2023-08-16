/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:41:59 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/16 21:36:58 by shikim           ###   ########.fr       */
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
	g_exit_code = 0;
	if (token_list->next == NULL)
	{
		chdir(get_env_value("HOME", env_list));
		set_oldpwd(env_list);
	}
	else if (token_list->next->next == NULL)
	{
		if (chdir(token_list->next->token) == -1)
		{
			error_cmd_no_file_dir(token_list->next->token);
			g_exit_code = 1;
		}
		else
			set_oldpwd(env_list);
	}
	return ;
}
