/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 18:01:17 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	p_tex(t_ray *ray, t_posd *raydir, t_system *sys, int side);

int	touch2(t_ray *ray, t_system *sys)
{
	int	hit;
	int	side;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			side = 1;
		}
		if (sys->play_map[ray->map.y][ray->map.x] == '1')
			hit = 1;
	}
	return (side);
}

int	touch(t_ray *ray, t_system *sys, t_posd *raydir, t_data *frame)
{
	int	side;

	side = touch2(ray, sys);
	if (side == 0)
		ray->walldist = (ray->sidedist.x - ray->deltadist.x);
	else
		ray->walldist = (ray->sidedist.y - ray->deltadist.y);
	ray->lineheight = (int)(HEIGTH / ray->walldist);
	ray->drawend = (ray->lineheight / 2) + (HEIGTH / 2);
	if (ray->drawend >= HEIGTH)
		ray->drawend = HEIGTH - 1;
	ray->drawstart = (-ray->lineheight / 2) + (HEIGTH / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->frame = frame;
	p_tex(ray, raydir, sys, side);
	return (0);
}

int	crtouch(t_posd *raydir, t_system *sys, t_ray *ray, t_data *frame)
{
	t_player	*player;

	player = sys->player;
	if (raydir->y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (player->pos.y
				- (double)ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = ((double)ray->map.y + 1.0
				- player->pos.y) * ray->deltadist.y;
	}
	return (touch(ray, sys, raydir, frame));
}

int	checkraytouch(t_posd *raydir, t_system *sys, int ipix, t_data *frame)
{
	t_ray		ray;
	t_player	*player;

	ray.ipix = ipix;
	player = sys->player;
	ray.map.x = (int)player->pos.x;
	ray.map.y = (int)player->pos.y;
	ray.deltadist.y = fabs(1 / raydir->y);
	ray.deltadist.x = fabs(1 / raydir->x);
	if (raydir->x < 0)
	{
		ray.step.x = -1;
		ray.sidedist.x = (player->pos.x - (double)ray.map.x) * ray.deltadist.x;
	}
	else
	{
		ray.step.x = 1;
		ray.sidedist.x = ((double)ray.map.x + 1.0
				- player->pos.x) * ray.deltadist.x;
	}
	return (crtouch(raydir, sys, &ray, frame));
}
