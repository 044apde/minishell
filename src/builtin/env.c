/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:55:47 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/09 16:25:20 by hyungjup         ###   ########.fr       */
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
		printf("%s=%s\n", list->key, list->value);
		list = list->next;
	}
	exit(0);
	return ;
}
