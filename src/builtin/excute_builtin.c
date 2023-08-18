/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shikim <shikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:33:06 by hyungjup          #+#    #+#             */
/*   Updated: 2023/08/18 20:25:32 by shikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin(t_token *token_list)
{
	t_token	*finded_node;

	finded_node = find_command(token_list);
	if (finded_node == NULL)
		return (FALSE);
	if (compare_str(finded_node->token, "echo") == TRUE)
		return (TRUE);
	else if (compare_str(finded_node->token, "cd") == TRUE)
		return (TRUE);
	else if (compare_str(finded_node->token, "pwd") == TRUE)
		return (TRUE);
	else if (compare_str(finded_node->token, "export") == TRUE)
		return (TRUE);
	else if (compare_str(finded_node->token, "unset") == TRUE)
		return (TRUE);
	else if (compare_str(finded_node->token, "env") == TRUE)
		return (TRUE);
	else if (compare_str(finded_node->token, "exit") == TRUE)
		return (TRUE);
	return (FALSE);
}

void	restore_standard_fd(int stdin_backup, int stdout_backup)
{
	dup2(stdin_backup, STDIN_FILENO);
	close(stdin_backup);
	dup2(stdout_backup, STDOUT_FILENO);
	close(stdout_backup);
	return ;
}

int	do_rdir(t_token *token_list)
{
	if (do_redirin(token_list) == ERROR)
		return (ERROR);
	if (do_redirout(token_list) == ERROR)
		return (ERROR);
	return (TRUE);
}

int	execute_builtin(t_token *token_list, t_env_list **env_list)
{
	int		stdin_backup;
	int		stdout_backup;
	t_token	*bulilt_in_node;

	stdin_backup = dup(STDIN_FILENO);
	stdout_backup = dup(STDOUT_FILENO);
	if (do_rdir(token_list) == ERROR)
		return (ERROR);
	bulilt_in_node = find_command(token_list);
	if (compare_str(bulilt_in_node->token, "echo") == TRUE)
		ft_echo(bulilt_in_node);
	else if (compare_str(bulilt_in_node->token, "cd") == TRUE)
		ft_cd(*env_list, bulilt_in_node);
	else if (compare_str(bulilt_in_node->token, "pwd") == TRUE)
		ft_pwd(bulilt_in_node, *env_list);
	else if (compare_str(bulilt_in_node->token, "export") == TRUE)
		ft_export(*env_list, bulilt_in_node);
	else if (compare_str(bulilt_in_node->token, "unset") == TRUE)
		ft_unset(env_list, bulilt_in_node);
	else if (compare_str(bulilt_in_node->token, "env") == TRUE)
		ft_env(*env_list);
	else if (compare_str(bulilt_in_node->token, "exit") == TRUE)
		ft_exit(bulilt_in_node);
	restore_standard_fd(stdin_backup, stdout_backup);
	return (0);
}
