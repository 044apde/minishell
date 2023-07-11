/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:10:14 by shikim            #+#    #+#             */
/*   Updated: 2023/07/11 20:49:09 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	kill_signal(char *input)
// {
// 	// if (ft_strncmp("^C", input, 2) == TRUE)
// 		// kill(1000, );
// }

void	sig_handler(int	sig)
{
	rl_on_new_line();
	return ;
}
