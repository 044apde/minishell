/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/07/21 21:13:31 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	parse_input(char *input, t_env_list *env_list)
{
	t_token	*head;

	head = split(input);
	check_type(head);
	substitution(head, env_list);
	unquote(head);
	check_syntax(head);
	show_token(head);
	// make_tree(head);
	return ;
}
