/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:55:47 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/15 21:01:04 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_env(t_env_list *env_list)
{
	int			i;
	t_env_list	*list;

	i = 0;
	list = env_list;
	while (list != NULL)
	{
		if (list->value == NULL)
		{
			list = list->next;
			continue ;
		}
		printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	g_exit_code = 0;
	return ;
}
