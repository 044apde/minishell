/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:27:17 by shikim            #+#    #+#             */
/*   Updated: 2023/07/12 16:28:40 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_minishell(int *pid)
{
	set_signal(pid);
	set_terminal();
	set_pid(pid);
	return ;
}