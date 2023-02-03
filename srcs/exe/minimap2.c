/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:34:00 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/01 09:46:06 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	ft_minimap(t_data *minimap, t_data *player, t_system *sys)
{
	if (sys->init_ok != 1)
	{
		init_minimap(sys, -1, -1, -1);
		sys->init_ok = 1;
	}
	minimap->img = mlx_new_image(sys->mlx, MPSIZE
			* MSIZE, MPSIZE * MSIZE);
	minimap->addr = mlx_get_data_addr(minimap->img, &minimap
			->bits_per_pixel, &minimap->line_length, &minimap->endian);
	player->img = mlx_new_image(sys->mlx, 10, 10);
	player->addr = mlx_get_data_addr(minimap->img, &minimap
			->bits_per_pixel, &minimap->line_length, &minimap->endian);
	print_mini(minimap, sys, 0, 0);
}
