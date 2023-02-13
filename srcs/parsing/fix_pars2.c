/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_pars2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:02:50 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/13 16:46:27 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	verif_one_dpre(char *tt, char **file, int mapl)
{
	int	i;
	int	r;

	i = -1;
	r = 0;
	while (file[++i] && i < mapl)
	{
		if (ft_strncmp(file[i], tt, ft_strlen(tt)) == 0)
			r++;
	}
	if (r != 1)
		return (-1);
	return (0);
}

int	fix_dpre(char **file, int mapl)
{
	int	r;

	r = 0;
	if (verif_one_dpre("NO ", file, mapl) == -1)
		r--;
	if (verif_one_dpre("SO ", file, mapl) == -1)
		r--;
	if (verif_one_dpre("WE ", file, mapl) == -1)
		r--;
	if (verif_one_dpre("EA ", file, mapl) == -1)
		r--;
	if (verif_one_dpre("C ", file, mapl) == -1)
		r--;
	if (verif_one_dpre("F ", file, mapl) == -1)
		r--;
	if (r < 0)
		return (-1);
	return (0);
}

int	i_line(char **map_t, char *st, int mapl)
{
	int	i;

	i = -1;
	while (map_t[++i] && i < mapl)
	{
		if (map_t[i][0] == st[0] && map_t[i][1] == st[1])
		{
			return (i);
		}
	}
	return (-1);
}

int	is_mapline(char **map)
{
	int	i;
	int	j;
	int	r;
	int	o;

	i = -1;
	while (map[++i])
	{
		j = -1;
		r = 0;
		o = 0;
		while (map[i][++j] && r == 0)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
				r = 1;
			else
			{
				if (map[i][j + 1] == 0 && o > 0)
					return (i);
				else
					o++;
			}
		}
	}
	return (-1);
}

int	verifmapf(char **map, int mapl, int i)
{
	while (map[++i] && i < mapl)
	{
		if (ft_strncmp(map[i], "NO ", 3) != 0
			&& ft_strncmp(map[i], "SO ", 3) != 0
			&& ft_strncmp(map[i], "WE ", 3) != 0
			&& ft_strncmp(map[i], "EA ", 3) != 0
			&& ft_strncmp(map[i], "C ", 2) != 0
			&& ft_strncmp(map[i], "F ", 2) != 0)
		{
			if (map[i][0] != 0)
				return (1);
		}
	}
	return (0);
}
