/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_blob2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:21:53 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/13 12:19:39 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

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

int	blob_error(char	*str)
{
	printf("%s\n", str);
	return (-1);
}
