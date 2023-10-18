/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:50:42 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/05 10:17:19 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_bis(t_errors error)
{
	if (error == JOIN)
		ft_putendl_fd(STDERR_FILENO, "Error : Problem ft_strjoin function.\n");
	if (error == WAIT)
		ft_putendl_fd(STDERR_FILENO, "Error : Problem wait function.\n");
}

void	errors(t_errors error, char *cmd)
{
	if (error == PIPE)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme with pipe function.\n");
	else if (error == CONDITIONS)
		ft_putendl_fd(STDERR_FILENO, "Error : Not enough parameters.\nOr the \
			environment is NULL.\n");
	else if (error == FORK)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme with fork function.\n");
	else if (error == DUP)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme with dup function.\n");
	else if (error == CLOSE)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme with close function.\n");
	else if (error == SPLIT)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme with split function.\n");
	else if (error == CMD && cmd != NULL)
		ft_putendl_fd(STDERR_FILENO, "Error : command not found.\n");
	else if (error == EXEC)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme with execv function.\n");
	else if (error == CLOSE_P0)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme closing pipe[0].\n");
	else if (error == CLOSE_P1)
		ft_putendl_fd(STDERR_FILENO, "Error : Probleme closing pipe[1].\n");
	error_bis(error);
	if (cmd == NULL)
		exit(1);
}
