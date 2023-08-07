/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:30:41 by shikim            #+#    #+#             */
/*   Updated: 2023/08/07 20:01:02 by shikim           ###   ########.fr       */
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
