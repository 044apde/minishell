/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:50:01 by shikim            #+#    #+#             */
/*   Updated: 2023/08/17 18:48:33 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_file_exist(char *file)
{
	if (access(file, F_OK) == -1)
	{
		ft_putstr_fd("\033[0;31mohmybash# ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
		ft_putstr_fd("\033[0;", 2);
		if (errno == ENOTDIR)
			exit(126);
		exit(127);
	}
}
