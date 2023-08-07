/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:41:11 by shikim            #+#    #+#             */
/*   Updated: 2023/08/07 20:16:02 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*parse_input(char *input, t_env_list *env_list)
{
	t_token	*head;

	if (pre_check_quote(input) == ERROR)
		return (NULL);
	head = split(input);
	printf("SPLIT\n");
	show_token(head);
	check_type(head);
	substitution(head, env_list);
	printf("SUBSTITUE\n");
	show_token(head);
	unquote(head);
	printf("UNQUOTE\n");
	show_token(head);
	if (check_syntax(head) == ERROR)
		return (NULL);
	return (head);
}
