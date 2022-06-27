/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 10:46:02 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/18 11:52:38 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

typedef struct s_data
{
	int	old_stdin;
	int	pipe;
}			t_data;

int	ft_strlen(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	return (i);
}

void	ft_cd(char **av)
{
	char	*error_arg = "error: cd: bad arguments\n";
	char	*error = "error: cd: cannot change directory ";

	if (av[1] == NULL || av[2] != NULL)
	{
		write(2, error_arg, ft_strlen(error_arg));
		return ;
	}
	if (chdir(av[1]) == -1)
	{
		write(2, error, ft_strlen(error));
		write(2, av[1], ft_strlen(av[1]));
		write(2, "\n", 1);
	}	
}

void	exec(t_data data, char **av, char **env)
{
	int	pid;
	int	fd[2];
	char	*error_fatal = "error: fatal\n";
	char	*error_execve = "error: cannot execute ";

	if (strcmp(av[0], "cd") == 0)
	{
		ft_cd(av);
		return ;
	}
	if (data.pipe == 1 && pipe(fd) == -1)
	{
		write(2, error_fatal, ft_strlen(error_fatal));
		close(data.old_stdin);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		write(2, error_fatal, ft_strlen(error_fatal));
		close(data.old_stdin);
		exit(1);
	}
	if (pid == 0)
	{
		if (data.pipe == 1)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
		}
		execve(av[0], av, env);
		write(2, error_execve, ft_strlen(error_execve));
		write(2, av[0], ft_strlen(av[0]));
		write(2, "\n", 1);
		close(data.old_stdin);
		exit(1);
	}
	else
	{
		if (data.pipe == 1)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
		}
		else
			dup2(data.old_stdin, 1);
		waitpid(pid, 0, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) env;
	int i = 1;
	int j = 1;
	t_data	data;

	data.old_stdin = dup(0);
	data.pipe = 0;
	while (av[i])
	{
		if (strcmp(av[i], "|") == 0 || strcmp(av[i], ";") == 0)
		{
			if (strcmp(av[i], "|") == 0)
				data.pipe = 1;
			av[i] = NULL;
			exec(data, av + j, env);
			data.pipe = 0;
			j = i + 1;
		}
		else if (av[i + 1] == NULL)
			exec(data, av + j, env);
		i++;
	}
	close(data.old_stdin);
	return (0);
}
