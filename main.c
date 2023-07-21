/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:01 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 17:48:47 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*input;

	init_minishell();
	while (TRUE)
	{
		input = read_input();
		parse_input(input);
		free(input);
	}
	return (0);
}
