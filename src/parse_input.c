/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/07/16 14:33:20 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parse_input(char *input)
{
	int		i;
	char	**arr;
	char	*dangling;

	i = 0;
	arr = split(input);
	if (arr == NULL)
		return ;
	show_token(arr);
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}
