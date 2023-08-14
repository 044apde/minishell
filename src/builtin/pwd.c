/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:47:43 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/14 22:14:10 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(t_token *bulilt_in_node)
{
	char	*buf;

	if (bulilt_in_node->next != NULL && \
			is_operator2(bulilt_in_node->next) == FALSE)
	{
		printf("\033[0;31mcd: too many arguments\033[0;0m\n");
		g_exit_code = 1;
		return ;
	}
	buf = getcwd(NULL, 0);
	ft_putstr_fd(buf, 1);
	ft_putstr_fd("\n", 1);
	free(buf);
	g_exit_code = 0;
	return ;
}
