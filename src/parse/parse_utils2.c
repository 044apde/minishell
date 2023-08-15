/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:30:41 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 19:59:46 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_operator(char *s)
{
	if (s == NULL)
		return (TRUE);
	else if (compare_str(s, "|") == TRUE)
		return (TRUE);
	else if (compare_str(s, "<") == TRUE)
		return (TRUE);
	else if (compare_str(s, ">") == TRUE)
		return (TRUE);
	else if (compare_str(s, "<<") == TRUE)
		return (TRUE);
	else if (compare_str(s, ">>") == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

void    show_token(t_token *head)
{
    t_token *node;

    node = head->next;
    printf("\033[0;34m===============PARSED TOKEN===================\n");
    while (node != NULL)
    {
        printf("[%s]:%d ", node->token, node->type);
        node = node->next;
    }
    node = head->next;
    printf("\n===============================================\033[0;0m\n");
    return ;
}
