/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_cb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:07 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/10 10:34:08 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	strlen2_cb(char *s1, char *set)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (s1[++i])
	{
		if (ft_memchr_cb(set, s1[i], ft_strlen_cb(set)))
			j++;
		else
		{
			while (s1[i])
				i++;
			while (--i > 0)
			{
				if (ft_memchr_cb(set, s1[i], ft_strlen_cb(set)))
					j++;
				else
					return (ft_strlen_cb(s1) - j);
			}
		}
	}
	return (ft_strlen_cb(s1) - j);
}

char	*ft_strtrim_cb(char *s1, char *set)
{
	char	*dup;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	dup = malloc(strlen2_cb(s1, set) + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (ft_memchr_cb(set, s1[i], ft_strlen_cb(set)))
		i++;
	ft_memcpy_cb(dup, &s1[i], strlen2_cb(s1, set));
	dup[strlen2_cb(s1, set)] = '\0';
	return (dup);
}
