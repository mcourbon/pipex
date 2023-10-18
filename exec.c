/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 10:12:47 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/20 15:15:31 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(int outin[2], char **av, char **env)
{
	int	id;

	id = fork();
	if (id == 0)
		return (exec_child(outin, av, env));
	else if (id == -1)
		return (errors(FORK, NULL), 1);
	else
		return (0);
}

int	parent(int outin[2], char **av, char **env)
{
	int	id;

	id = fork();
	if (id == 0)
		return (exec_parent(outin, av, env));
	else if (id == -1)
		return (errors(FORK, NULL), 1);
	else
		return (0);
}

int	exec_child(int outin[2], char **av, char **env)
{
	char	*cmd;
	char	**splitted;
	int		infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		return (ft_putendl_fd(2, "Error"), ft_putendl(""), 1);
	if (dup2(infile, STDIN_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (dup2(outin[1], STDOUT_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (close(infile) == -1)
		return (errors(CLOSE, NULL), 1);
	splitted = ft_split(av[2], ' ');
	if (splitted == NULL)
		return (errors(SPLIT, NULL), 1);
	cmd = cmd_build(splitted[0], env);
	if (cmd == NULL)
		return (free_all(splitted), 1);
	if (close_pipe(outin) == 1)
		return (free(cmd), free_all(splitted), errors(CLOSE, NULL), 1);
	if (execve(cmd, splitted, env) == -1)
		errors(EXEC, "0");
	return (free(cmd), free_all(splitted), 1);
}

int	exec_parent(int outin[2], char **av, char **env)
{
	char	*cmd;
	char	**splitted;
	int		outfile;

	outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (outfile < 0)
		return (ft_putendl_fd(2, "Error"), 1);
	if (dup2(outin[0], STDIN_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		return (errors(DUP, NULL), 1);
	if (close(outfile) == 1)
		return (errors(CLOSE, NULL), 1);
	splitted = ft_split(av[3], ' ');
	if (splitted == NULL)
		return (errors(SPLIT, NULL), 1);
	cmd = cmd_build(splitted[0], env);
	if (cmd == NULL)
		return (free_all(splitted), 1);
	if (close_pipe(outin) == 1)
		return (free(cmd), free_all(splitted), errors(CLOSE, NULL), 1);
	if (execve(cmd, splitted, env) == -1)
		errors(EXEC, "0");
	return (free(cmd), free_all(splitted), 1);
}
