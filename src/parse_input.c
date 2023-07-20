/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 04:11:35 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_input(char *input)
{
	t_token *head;

	head = split(input);
	// To do: check token
	// substitution
	// check syntax
	// treeing
	return ;
}
