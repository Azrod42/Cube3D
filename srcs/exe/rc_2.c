/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 16:01:27 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_line line, t_data *frame)
{
	int	i;

	i = line.drawstart;
	while (i < line.drawend)
	{
		my_mlx_pixel_put(frame, line.ipix, i, line.color);
		i++;
	}
}

void	p_tex2(t_ptex px, int side, t_posd *raydir, t_system *sys)
{
	while (px.y <= px.ray->drawend)
	{
		px.tex_y = (int)px.texpos & (IMGS - 1);
		px.texpos += px.step;
		if (side == 0 && raydir->x > 0)
			px.color = sys->txt->txts[0][(int)(IMGS * px.tex_y + px.tex_x)];
		else if (side == 0 && raydir->x <= 0)
			px.color = sys->txt->txts[1][(int)(IMGS * px.tex_y + px.tex_x)];
		else if (side == 1 && raydir->y > 0)
			px.color = sys->txt->txts[2][(int)(IMGS * px.tex_y + px.tex_x)];
		else
			px.color = sys->txt->txts[3][(int)(IMGS * px.tex_y + px.tex_x)];
		my_mlx_pixel_put(px.ray->frame, px.ray->ipix, px.y, px.color);
		px.y++;
	}
}

void	p_tex(t_ray *ray, t_posd *raydir, t_system *sys, int side)
{
	t_ptex	px;

	px.texnum = sys->play_map[ray->map.y][ray->map.x] - 1;
	if (side == 0)
		px.wallx = sys->player->pos.y + (ray->walldist * raydir->y);
	else
		px.wallx = sys->player->pos.x + (ray->walldist * raydir->x);
	px.wallx -= (int)(px.wallx);
	px.tex_x = (int)(px.wallx * (double)(IMGS));
	if (side == 0 && raydir->x > 0)
		px.tex_x = IMGS - px.tex_x - 1;
	if (side == 1 && raydir->y < 0)
		px.tex_x = IMGS - px.tex_x - 1;
	px.step = 1.0 * IMGS / ray->lineheight;
	px.texpos = (ray->drawstart - (HEIGTH / 2)
			+ (ray->lineheight / 2)) * px.step;
	px.y = ray->drawstart;
	px.ray = ray;
	p_tex2(px, side, raydir, sys);
}
