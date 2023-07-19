/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:59:07 by shikim            #+#    #+#             */
/*   Updated: 2023/07/19 18:44:47 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_pid(int	*pid)
{
	*pid = getpid();
	return ;
}

void	exit_program(void)
{
	printf("Error: failed to malloc\n");
	exit(1);
}
