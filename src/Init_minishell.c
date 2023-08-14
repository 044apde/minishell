/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:27:17 by shikim            #+#    #+#             */
/*   Updated: 2023/08/14 14:56:45 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	trash_can(int argc, char **argv)
{
	argc++;
	argc--;
	argv++;
	argv--;
	return ;
}

void	init_minishell(int argc, char **argv)
{
	g_exit_code = 0;
	trash_can(argc, argv);
	set_signal();
	set_terminal();
	return ;
}
