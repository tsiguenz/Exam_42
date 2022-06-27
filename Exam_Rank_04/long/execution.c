/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:49:39 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/17 17:55:57 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

void	ft_cd(t_cmd *cmd)
{
	if (cmd->args[1] == NULL || cmd->args[2] != NULL)
		write(2, "error: cd: bad arguments\n", 25);
	else if (chdir(cmd->args[1]) == -1)
	{
		write(2, "error: cd: cannot change directory to ", 39);
		write(2, cmd->args[1], ft_strlen(cmd->args[1]));
		write(2, "\n", 1);
	}
}

int	execution(t_cmd *cmd, char **env)
{
	(void) cmd;
	(void) env;
	int	pid;
	int	pipefd[2];
	int	old_stdin = dup(1);
	
	first_cmd(&cmd);
	while (cmd != NULL)
	{
		if (strcmp(cmd->args[0], "cd") == 0)
			ft_cd(cmd);
		if (cmd->sep == '|' && pipe(pipefd) == -1)
		{
			write(2, "error: fatal\n", 13);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			write(2, "error: fatal\n", 13);
			return (1);
		}
		if (pid == 0)
		{
			if (cmd->sep == '|')
			{
				close(pipefd[0]);
				dup2(pipefd[1], 1);
				close(pipefd[1]);
			}
			execve(cmd->args[0], cmd->args, env);
			write(2, "error: cannot execute ", 22);
			write(2, cmd->args[0], ft_strlen(cmd->args[0]));
			write(2, "\n", 1);
			exit(1);
		} else
		{
			if (cmd->sep == '|')
			{
				close(pipefd[1]);
				dup2(pipefd[0], 0);
				close(pipefd[0]);
			} else
				dup2(old_stdin, 0);
			waitpid(pid, 0, 0);
		}
		cmd = cmd->next;
	}
	return (0);
}
