/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:31:48 by shikim            #+#    #+#             */
/*   Updated: 2023/07/11 20:35:41 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_input_to_history(char *input)
{
	add_history(input);
	return ;
}

char	*read_input(int pid)
{
	char	*input;

	pid++;
	input = readline("minishell # ");
	add_input_to_history(input);
	return (input);
}
