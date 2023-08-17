/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:47:43 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/17 15:14:42 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_token *bulilt_in_node, t_env_list *env_list)
{
	char	*now_pwd;

	if (bulilt_in_node->next != NULL && \
			is_operator2(bulilt_in_node->next) == FALSE)
	{
		ft_putstr_fd("\033[0;31mohmybash# : pwd: too many arguments\033[0;0m\n", 2);
		g_exit_code = 1;
		return ;
	}
	now_pwd = get_env(env_list, "NOWPWD");
	printf("%s\n", now_pwd);
	free(now_pwd);
	g_exit_code = 0;
	return ;
}
