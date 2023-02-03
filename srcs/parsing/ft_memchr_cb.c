/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_cb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:33:52 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/10 10:33:53 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	*ft_memchr_cb(const void *s, int c, size_t n)
{
	size_t	i;
	char	*p;
	void	*r;

	p = (char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
		{
			r = &p[i];
			return (r);
		}
		i++;
	}
	return (NULL);
}
