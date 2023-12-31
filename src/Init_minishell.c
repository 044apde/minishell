/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:27:17 by shikim            #+#    #+#             */
/*   Updated: 2023/08/16 15:20:02 by shikim           ###   ########.fr       */
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
	trash_can(argc, argv);
	set_signal();
	set_terminal();
	return ;
}
