/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:19:49 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/20 15:02:03 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_command(char *str, char *new)
{
	char	**path;
	char	*cmd;
	int		i;

	path = ft_split(new, ':');
	free(new);
	if (path == NULL)
		return (ft_putendl("Error"), NULL);
	i = -1;
	while (path[++i])
	{
		new = ft_strjoin(path[i], "/");
		if (new == NULL)
			return (free_all(path), errors(JOIN, "0"), NULL);
		cmd = ft_strjoin(new, str);
		free(new);
		new = NULL;
		if (cmd == NULL)
			return (free_all(path), errors(JOIN, "0"), NULL);
		if (access(cmd, F_OK | X_OK) == 0)
			return (free_all(path), cmd);
	}
	return (cmd);
}

static char	*check_slash(char *cmd, char *str)
{
	if (ft_in('/', str) == 1)
	{
		cmd = ft_strdup(str);
		if (cmd == NULL)
			return (ft_putendl("Error"), NULL);
		if (access(cmd, F_OK | X_OK) == -1)
			return (errors(CMD, str), free(cmd), NULL);
		return (cmd);
	}
	return (cmd);
}

char	*cmd_build(char *str, char **env)
{
	int		new;
	char	*cmd;
	size_t	i;

	i = 0;
	cmd = NULL;
	cmd = check_slash(cmd, str);
	if (cmd == NULL && ft_in('/', str) == 1)
		return (NULL);
	while (env[i])
	{
		new = ft_strncmp(env[i], "PATH=", 5);
		if (!new)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	cmd = ft_strdup(&env[i][5]);
	if (!cmd)
		return (ft_putendl("Error"), NULL);
	cmd = search_command(str, cmd);
	if (cmd == NULL)
		return (errors(CMD, str), NULL);
	return (cmd);
}
