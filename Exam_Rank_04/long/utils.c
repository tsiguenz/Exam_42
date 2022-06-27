/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:05:57 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/17 17:42:09 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(const char *s)
{
	int	i = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	int	i = 0;

	if (s == NULL)
		return (NULL);
	ret = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (ret == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int	exit_fatal(void)
{
	write(2, "error: fatal\n", 13);
	return (1);
}

void	*void_exit_fatal(void)
{
	write(2, "error: fatal\n", 13);
	return (NULL);
}

void	print_args(char **args)
{
	int	i = 0;

	if (args == NULL)
		return ;
	while (args[i] != NULL)
	{
		printf("args[%d] = %s\n", i, args[i]);
		i++;
	}
}

void	print_cmds(t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	first_cmd(&tmp);
	while (tmp != NULL)
	{
		printf("%s\n", "----------------------------------------");
		print_args(tmp->args);
		printf("sep = %c\n", tmp->sep);
		printf("%s\n", "----------------------------------------");
		tmp = tmp->next;
	}
}

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (cmd == NULL)
		return (void_exit_fatal());
	cmd->args = NULL;
	cmd->sep = 0;
	cmd->next = NULL;
	cmd->prev = NULL;
	return (cmd);
}

void	free_one_cmd(t_cmd **cmd)
{
	int	i = 0;

	if ((*cmd)->args != NULL)
	{
		while ((*cmd)->args[i] != NULL)
		{
			free((*cmd)->args[i]);
			i++;
		}
		free((*cmd)->args);
	}
	free(*cmd);
}

void	free_cmds(t_cmd **cmd)
{
	t_cmd	*freable;

	first_cmd(cmd);
	while (*cmd != NULL)
	{
		freable = *cmd;
		*cmd = (*cmd)->next;
		free_one_cmd(&freable);
	}
}

void	first_cmd(t_cmd **cmd)
{
	while ((*cmd)->prev != NULL)
		*cmd = (*cmd)->prev;
}
