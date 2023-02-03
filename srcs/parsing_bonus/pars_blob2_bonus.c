/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_blob2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:21:53 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/10 11:24:21 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	replace_otherchar(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'T')
				map[i][j] = '1';
			else if (map[i][j] == 'P')
				map[i][j] = '0';
			else if (map[i][j] == 'F')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

t_pos	find_start_player(char **map)
{
	t_pos	p_pos;

	p_pos.y = 0;
	while (map[p_pos.y])
	{
		p_pos.x = 0;
		while (map[p_pos.y][p_pos.x])
		{
			if (map[p_pos.y][p_pos.x] == 'N' || map[p_pos.y][p_pos.x] == 'S' ||
					map[p_pos.y][p_pos.x] == 'W'
					|| map[p_pos.y][p_pos.x] == 'E')
				return (p_pos);
			p_pos.x++;
		}
		p_pos.y++;
	}
	return (p_pos);
}
