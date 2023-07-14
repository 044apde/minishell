/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:01 by shikim            #+#    #+#             */
/*   Updated: 2023/07/14 21:42:16 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;
	int		pid;

	init_minishell(&pid);
	while (TRUE)
	{
		input = read_input(pid);
		parse_input(input);
		free(input);
	}
	return (0);
}
