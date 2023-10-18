/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:08:50 by shifterpro        #+#    #+#             */
/*   Updated: 2023/10/04 14:14:53 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*dest;

	i = 0;
	dest = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

void	free_all(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
		free(splitted[i++]);
	free(splitted);
}

int	close_pipe(int outin[2])
{
	if (close(outin[0]) == -1)
		return (errors(CLOSE_P0, "0"), 1);
	if (close(outin[1]) == -1)
		return (errors(CLOSE_P1, "0"), 1);
	return (0);
}
