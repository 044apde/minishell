/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:01 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 21:12:17 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_env_list	*env_list;

	env_list = set_env(envp);
	init_minishell(argc, argv);
	while (TRUE)
	{
		input = read_input();
		parse_input(input, env_list);
		free(input);
	}
	return (0);
}
