/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_cub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:50:39 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/15 14:31:20 by tsorabel         ###   ########.fr       */
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

void	crgb(char **s, int ln, int *i, int *nb)
{
	*i = 1;
	while (s[ln][*i] == 32 || (s[ln][*i] >= 9 && s[ln][*i] <= 13))
		*i += 1;
	*nb = ft_atoi(&s[ln][*i]);
	*i -= 1;
}

int	check_rgb(char **s, int ln, int count, int comac)
{
	int	i;
	int	nb;

	print_char_tab(s);
	if (precheck(s, ln, 0) == -1)
		return (-1);
	crgb(s, ln, &i, &nb);
	while (s[ln][++i])
	{
		if ((s[ln][i] >= '0' && s[ln][i] <= '9') || s[ln][i] == 32)
			count++;
		if (s[ln][i] == ',')
		{
			count = 0;
			comac++;
			nb = ft_atoi(&s[ln][i + 1]);
		}
		if (count > 3 || comac > 3 || ((s[ln][i] < '0' || nb < 0 || s[ln][i]
			> '9') && s[ln][i] != ',' && s[ln][i] != ' ') || nb > 255)
		{
			printf("Invalid RGB\n");
			return (-1);
		}
	}
	return (0);
}
