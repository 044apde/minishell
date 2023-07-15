/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/07/15 17:17:16 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_input(char *input)
{
	char	**arr;
	char	*dangling;

	arr = split(input);
	while (*arr != NULL)
	{
		printf("%s\n", *arr);
		arr++;
	}
	return ;
}
