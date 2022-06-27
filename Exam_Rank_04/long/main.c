/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:13:51 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/17 17:56:30 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	main(int ac, char **av, char **envp)
{
	(void) envp;
	t_cmd *cmd = parsing(ac, av);

	if (cmd == NULL)
		return (1);
	if (cmd == NULL)
		return (0);
	execution(cmd, envp);
	free_cmds(&cmd);
	return (0);
}
