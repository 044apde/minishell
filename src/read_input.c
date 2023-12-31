/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:31:48 by shikim            #+#    #+#             */
/*   Updated: 2023/08/18 20:01:32 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_input_to_history(char *input)
{
	add_history(input);
	return ;
}

char	*read_input(void)
{
	char	*input;

	input = readline("\033[0;32mohmybash#\033[0m ");
	if (input == NULL)
		term_handler();
	add_input_to_history(input);
	return (input);
}
