/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/08/17 17:58:20 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*parse_input(char *input, t_env_list *env_list)
{
	t_token	*head;

	if (pre_check_quote(input) == ERROR)
		return (NULL);
	head = split(input);
	check_type(head);
	substitution(head, env_list);
	unquote(head);
	if (check_syntax(head) == ERROR)
	{
		g_exit_code = 258;
		ft_putstr_fd("\033[0;31mohmybash# Check syntax\033[0;0m\n", 2);
		free_token_list(head);
		return (NULL);
	}
	return (head);
}

t_token	*parse_origin_input(char *input)
{
	t_token	*head;

	head = split(input);
	check_type(head);
	unquote(head);
	return (head);
}
