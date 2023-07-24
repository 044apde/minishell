/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/07/24 20:46:19 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*parse_input(char *input, t_env_list *env_list)
{
	t_token	*head;

	head = split(input);
	check_type(head);
	substitution(head, env_list);
	unquote(head);
	if (check_syntax(head) == ERROR)
		return (NULL);
	show_token(head);
	return (head);
}
