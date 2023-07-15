/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:09:09 by shikim            #+#    #+#             */
/*   Updated: 2023/07/15 17:13:24 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	make_redir_in(char **arr, char *s, int st, int i)
{
	static int	redir_in;

	if (s[st + 1] != '<')
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			arr[i] = ft_strdup("<<");
			return (TRUE);
		}
		redir_in = 0;
		arr[i] = ft_strdup("<");
		return (TRUE);
	}
	else
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			arr[i] = ft_strdup("<<");
			return (TRUE);
		}
		redir_in = 1;
		return (FALSE);
	}
}

int	make_redir_out(char **arr, char *s, int st, int i)
{
	static int	redir_out;

	if (s[st + 1] != '>')
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			arr[i] = ft_strdup(">>");
			return (TRUE);
		}
		redir_out = 0;
		arr[i] = ft_strdup(">");
		return (TRUE);
	}
	else
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			arr[i] = ft_strdup(">>");
			return (TRUE);
		}
		redir_out = 1;
		return (FALSE);
	}
}
