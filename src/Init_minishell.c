/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:27:17 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 21:33:53 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	trash_can(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return ;
}

void	init_minishell(int argc, char **argv)
{
	trash_can(argc, argv);
	set_signal();
	set_terminal();
	return ;
}
