/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:16:11 by shikim            #+#    #+#             */
/*   Updated: 2023/08/12 17:18:17 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	custom_WIFEXITED(int status)
{
	return ((status & 0x7F) == 0);
}

int	custom_WEXITSTATUS(int status)
{
	return ((status >> 8) & 0xFF);
}

int	custom_WIFSIGNALED(int status)
{
	return (((status & 0x7F) != 0) && (((status >> 8) & 0xFF) == 0));
}

int	custom_WTERMSIG(int status)
{
	return (status & 0x7F);
}
