/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 22:52:14 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/20 13:37:38 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_unset(char **envp)
{
	char	*str;
	int		i;
	char	**env_list;

	env_list = init_env_list(envp);
	if (argv[1] == NULL)
		return (0);
	i = 1;
	while ()
}
