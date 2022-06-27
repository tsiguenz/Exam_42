/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:06:19 by tsiguenz          #+#    #+#             */
/*   Updated: 2022/04/18 15:27:10 by tsiguenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL
#define MICROSHELL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	char			**args;
	char			sep;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}			t_cmd;

t_cmd	*parsing(int ac, char **av);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
int		exit_fatal(void);
void	*void_exit_fatal(void);
void	print_args(char **args);
void	print_cmds(t_cmd **cmd);
t_cmd	*new_cmd(void);
void	free_one_cmd(t_cmd **cmd);
void	first_cmd(t_cmd **cmd);
void	free_cmds(t_cmd **cmd);
int		execution(t_cmd *cmd, char **env);
#endif
