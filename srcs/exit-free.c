/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit-free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:12:47 by tsorabel          #+#    #+#             */
/*   Updated: 2023/02/03 09:29:41 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_all_cb(t_system *sys)
{
	sys->end = 1;
	exit(0);
}

char	*malloced(char *p)
{
	p = malloc (sizeof(char));
	p[0] = 0;
	return (p);
}

char	*remove_nl(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	new = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (str[++i])
	{
		if (i > 0 && str[i] == '\n' && str[i - 1] == '\n' && str[i - 2] == '\n')
		{
			while (str[++i] == '\n')
				;
			i--;
		}
		else
		{
			new[j] = str[i];
			j++;
		}
	}
	new[i] = '\0';
	free(str);
	return (new);
}

int	check_rgb(char **s, int ln, int count, int comac)
{
	int	i;
	int	nb;

	i = 0;
	while (s[ln][++i] == 32 || (s[ln][i] >= 9 && s[ln][i] <= 13))
		;
	nb = ft_atoi(&s[ln][i--]);
	while (s[ln][++i])
	{
		if (s[ln][i] >= '0' && s[ln][i] <= '9')
			count++;
		if (s[ln][i] == ',')
		{
			count = 0;
			comac++;
			nb = ft_atoi(&s[ln][i + 1]);
		}
		if (count > 3 || comac > 3 || ((s[ln][i] < '0' || nb < 0
				|| s[ln][i] > '9') && s[ln][i] != ',') || nb > 255)
		{
			printf("Invalid RGB\n");
			return (-1);
		}
	}
	return (0);
}