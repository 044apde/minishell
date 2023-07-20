/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:09:09 by shikim            #+#    #+#             */
/*   Updated: 2023/07/20 14:38:38 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	make_redir_in(t_token *head, char *s, int st)
{
	static int	redir_in;

	if (s[st + 1] != '<')
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			insert_node(head, "<<");
			return ;
		}
		redir_in = 0;
		insert_node(head, "<");
	}
	else
	{
		if (redir_in == 1)
		{
			redir_in = 0;
			insert_node(head, "<<");
			return ;
		}
		redir_in = 1;
		return ;
	}
}

void	make_redir_out(t_token *head, char *s, int st)
{
	static int	redir_out;

	if (s[st + 1] != '>')
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			insert_node(head, ">>");
			return ;
		}
		redir_out = 0;
		insert_node(head, ">");
	}
	else
	{
		if (redir_out == 1)
		{
			redir_out = 0;
			insert_node(head, ">>");
			return ;
		}
		redir_out = 1;
		return ;
	}
}

int	check_quote1(char c)
{
	static int	double_flag = 0;

	if (c == '"')
	{
		if (double_flag == 0)
		{
			double_flag = 1;
			return (TRUE);
		}
		else if (double_flag == 1)
		{
			double_flag = 0;
			return (DONE);
		}
	}
	else
	{
		if (double_flag == 1)
			return (TRUE);
		return (FALSE);
	}
	return (FALSE);
}

int	check_quote2(char c)
{
	static int	single_flag = 0;

	if (c == '\'')
	{
		if (single_flag == 0)
		{
			single_flag = 1;
			return (TRUE);
		}
		else if (single_flag == 1)
		{
			single_flag = 0;
			return (DONE);
		}
	}
	else
	{
		if (single_flag == 1)
		{
			return (TRUE);
		}
		return (FALSE);
	}
	return (FALSE);
}
