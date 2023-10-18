/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:01:35 by mcourbon          #+#    #+#             */
/*   Updated: 2023/09/20 14:59:02 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] == s2[i]) && i < n)
	{
		if (s1[i] == 0)
			return (0);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
}
