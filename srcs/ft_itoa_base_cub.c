/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_cub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:50:39 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 10:12:20 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*ft_itoa_base_write_cub(char *final, int len, long nb, char *base)
{
	int	tbase;

	tbase = 16;
	if (nb < 0)
		nb *= -1;
	final[len] = 0;
	while (--len >= 0)
	{
		final[len] = base[nb % tbase];
		nb /= tbase;
	}
	return (final);
}

char	*ft_itoa_base_cub(int nbr, int len)
{
	char		*final;

	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (0);
	return (ft_itoa_base_write_cub(final, len, nbr, "0123456789ABCDEF"));
}
