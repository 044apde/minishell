/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 20:52:44 by shikim            #+#    #+#             */
/*   Updated: 2023/08/07 20:19:06 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_d_index(char *token)
{
	int	index;

	index = -1;
	while (token[++index] != '\0')
	{
		if (token[index] == '$')
			return (index);
	}
	return (ERROR);
}

int	find_s_index(char *token, int d_index)
{
	int	index;

	index = d_index;
	while (token[++index] != '\0')
	{
		if (is_sep(token[index]) == TRUE)
			return (index);
	}
	return (ERROR);
}

char	*make_substitute(char *token, t_env_list *env_list)
{
	char	*dangling;
	char	*new_token;
	char	*env_token;
	int		d_index;
	int		s_index;

	d_index = find_d_index(token);
	s_index = find_s_index(token, d_index);
	if (s_index == ERROR || d_index == ERROR)
		return (NULL);
	env_token = get_env(env_list, ft_substr(token, d_index, s_index - d_index));
	if (env_token == NULL)
		env_token = ft_strdup("\n");
	new_token = ft_substr(token, 0, d_index);
	dangling = new_token;
	new_token = ft_strjoin(new_token, env_token);
	free(dangling);
	dangling = new_token;
	new_token = ft_strjoin(new_token, ft_substr(token, s_index, \
					ft_strlen(token) - d_index));
	free(dangling);
	return (new_token);
}
