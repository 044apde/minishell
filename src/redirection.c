/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 15:52:49 by hyungjup          #+#    #+#             */
/*   Updated: 2023/07/19 14:48:42 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "minishell.h"

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

char	*find_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*new_cmd;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		new_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(new_cmd, 0) == 0)
			return (new_cmd);
		free(new_cmd);
		path++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	fd[0] = open("infile", O_RDONLY);
	fd[1] = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		printf("open error\n");
		exit(1);
	}
	return (0);
}
