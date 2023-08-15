/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 04:13:36 by shikim            #+#    #+#             */
/*   Updated: 2023/08/15 20:38:59 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	compare_str(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	if (str1[i] != '\0' || str2[i] != '\0')
		return (FALSE);
	return (TRUE);
}

void	check_type(t_token *head)
{
	t_token	*node;

	node = head->next;
	while (node != NULL)
	{
		if (compare_str("<<", node->token) == TRUE)
			node->type = HEREDOC;
		else if (compare_str(">>", node->token) == TRUE)
			node->type = APPEND;
		else if (compare_str("<", node->token) == TRUE)
			node->type = REDIR_IN;
		else if (compare_str(">", node->token) == TRUE)
			node->type = REDIR_OUT;
		else if (compare_str("|", node->token) == TRUE)
			node->type = PIPE;
		else if (node->token[0] == '"')
			node->type = D_QUOTE;
		else if (node->token[0] == '\'')
			node->type = S_QUOTE;
		else
			node->type = WORD;
		node = node->next;
	}
	return ;
}

void	substitution(t_token *head, t_env_list *env_list)
{
	t_token	*n;
	char	*sub;

	n = head->next;
	while (n != NULL)
	{
		if (n->type == WORD || n->type == D_QUOTE)
		{
			sub = make_substitute(n->token, env_list);
			if (sub == NULL)
				;
			else
			{
				free(n->token);
				n->token = sub;
			}
		}
		n = n->next;
	}
	return ;
}

void	unquote(t_token *head)
{
	t_token	*node;
	char	*dangling;

	node = head->next;
	while (node != NULL)
	{
		if (node->type == D_QUOTE)
		{
			dangling = node->token;
			node->token = ft_strtrim(node->token, "\"");
			free(dangling);
		}
		else if (node->type == S_QUOTE)
		{
			dangling = node->token;
			node->token = ft_strtrim(node->token, "\'");
			free(dangling);
		}
		node = node->next;
	}
	return ;
}

int	check_syntax(t_token *head)
{
	t_token	*n;

	n = head->next;
	while (n != NULL)
	{
		if (is_operator(n->token) == TRUE)
		{
			if (n->next == NULL)
				return (ERROR);
			else if (n->type != PIPE && is_operator(n->next->token) == TRUE)
				return (ERROR);
			else if (n->type == PIPE && n->prev->token == NULL)
				return (ERROR);
		}
		n = n->next;
	}
	return (TRUE);
}
