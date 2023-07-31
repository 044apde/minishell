/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:01 by shikim            #+#    #+#             */
/*   Updated: 2023/07/28 22:40:02 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	t_env_list	*env_list;
	t_token		*token_list;

	env_list = set_env(envp);
	init_minishell(argc, argv);
	while (TRUE)
	{
		input = read_input();
		token_list = parse_input(input, env_list);
		execute(token_list, env_list);
		free(input);
	}
	return (0);
}
