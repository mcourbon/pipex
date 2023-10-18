/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:50:12 by shifterpro        #+#    #+#             */
/*   Updated: 2023/09/19 18:09:32 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	outin[2];

	if (ac == 5 && env != NULL)
	{
		if (pipe(outin) == -1)
			return (errors(PIPE, NULL), 1);
		if (child(outin, av, env) == 1)
			return (1);
		if (parent(outin, av, env) == 1)
			return (1);
		close_pipe(outin);
		if (wait(NULL) == -1)
			return (errors(WAIT, NULL), 1);
		if (wait(NULL) == -1)
			return (errors(WAIT, NULL), 1);
	}
	else
		errors(CONDITIONS, NULL);
	return (0);
}
