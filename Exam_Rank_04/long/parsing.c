/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:10:10 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/13 15:16:17 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	new_arg(char *av, t_cmd **cmd)
{
	int	i = 0;
	char **new_arg = NULL;

	if ((*cmd)->args == NULL)
	{
		(*cmd)->args = malloc(2 * sizeof(char *));
		if ((*cmd)->args == NULL)
			return (exit_fatal());
		(*cmd)->args[0] = ft_strdup(av);
		if ((*cmd)->args[0] == NULL)
			return (exit_fatal());
		(*cmd)->args[1] = NULL;
	}
	else
	{
		while ((*cmd)->args[i] != NULL)
			i++;
		new_arg = malloc((i + 2) * sizeof(char *));
		if (new_arg == NULL)
			return (exit_fatal());
		i = 0;
		while ((*cmd)->args[i] != NULL)
		{
			new_arg[i] = ft_strdup((*cmd)->args[i]);
			if (new_arg[i] == NULL)
				return (exit_fatal());
			free((*cmd)->args[i]);
			i++;
		}
		new_arg[i] = ft_strdup(av);
		if (new_arg[i] == NULL)
			return (exit_fatal());
		new_arg[i + 1] = NULL;
		free((*cmd)->args);
		(*cmd)->args = new_arg;
	}
	return (0);
}

int	parse_elem(char *av, t_cmd **cmd)
{
	if (strcmp(av, "|") == 0 || strcmp(av, ";") == 0)
	{
		(*cmd)->sep = av[0];
		t_cmd	*new = new_cmd();
		if (new == NULL)
			return (exit_fatal());
		(*cmd)->next = new;
		new->prev = *cmd;
		*cmd = (*cmd)->next;
	}
	else if (new_arg(av, cmd) == 1)
		return (exit_fatal());
	return (0);
}

t_cmd	*parsing(int ac, char **av)
{
	t_cmd	*cmd = NULL;
	int		i = 1;

	if (ac == 1)
		return (NULL);
	cmd = new_cmd();
	if (cmd == NULL)
		return (NULL);
	while (i < ac)
	{
		parse_elem(av[i], &cmd);
		i++;
	}
	return (cmd);
}
