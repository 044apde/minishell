/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:57:01 by shikim            #+#    #+#             */
/*   Updated: 2023/08/09 15:53:00 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char				*input;
	t_env_list			*env_list;
	t_token				*token_list;
	struct sigaction	act_new;

	env_list = set_env(envp);
	init_minishell(argc, argv, act_new);
	while (TRUE)
	{
		input = read_input();
		token_list = parse_input(input, env_list);
		execute(token_list, env_list, act_new);
		free(input);
		free_token_list(token_list);
	}
	return (0);
}
