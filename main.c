/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:01 by shikim            #+#    #+#             */
/*   Updated: 2023/08/16 15:12:06 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code = 0;

int	main(int argc, char **argv, char **envp)
{
	char				*input;
	t_env_list			*env_list;
	t_token				*token_list;
	t_token				*origin_list;

	env_list = set_env(envp);
	init_minishell(argc, argv);
	while (TRUE)
	{
		input = read_input();
		token_list = parse_input(input, env_list);
		origin_list = parse_origin_input(input);
		execute(token_list, env_list, origin_list);
		free(input);
		free_token_list(token_list);
		free_token_list(origin_list);
	}
	return (0);
}
