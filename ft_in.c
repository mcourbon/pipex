/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:23:20 by shifterpro        #+#    #+#             */
/*   Updated: 2023/08/31 12:25:16 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_in(const char c, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
			return (1);
		i++;
	}
	return (0);
}
