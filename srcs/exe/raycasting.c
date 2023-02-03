/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 17:59:53 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	checkraytouch(t_posd *raydir, t_system *sys, int ipix, t_data *frame);

void	draw_back(t_system *sys, int i, t_raycst *cast)
{
	t_line	up;
	t_line	down;

	up.color = sys->back_color[0];
	down.color = sys->back_color[1];
	up.drawstart = 0;
	up.drawend = HEIGTH / 2;
	down.drawstart = HEIGTH / 2;
	down.drawend = HEIGTH;
	up.ipix = i;
	down.ipix = i;
	draw_line(up, &cast->frame);
	draw_line(down, &cast->frame);
}

int	reset_image(t_raycst *cast, t_system *sys)
{
	mlx_destroy_image(sys->mlx, cast->frame.img);
	mlx_destroy_image(sys->mlx, cast->minimap.img);
	mlx_destroy_image(sys->mlx, cast->playermini.img);
	return (0);
}

int	raycasting(t_system	*sys, t_player *player, double div)
{
	t_raycst	raycst;

	raycst.w = WIDTH;
	raycst.i = 0;
	div = (raycst.w / 2);
	raycst.frame.img = mlx_new_image(sys->mlx, WIDTH, HEIGTH);
	raycst.frame.addr = mlx_get_data_addr(raycst.frame.img,
			&raycst.frame.bits_per_pixel,
			&raycst.frame.line_length, &raycst.frame.endian);
	ft_minimap(&raycst.minimap, &raycst.playermini, sys);
	while (raycst.i < WIDTH)
	{
		raycst.camx = ((2 * raycst.i) / raycst.w) - 1;
		raycst.raydir.x = player->rotation.x + player->plane.x * raycst.camx;
		raycst.raydir.y = player->rotation.y + player->plane.y * raycst.camx;
		draw_back(sys, raycst.i, &raycst);
		checkraytouch(&raycst.raydir, sys, raycst.i, &raycst.frame);
		raycst.i++;
	}
	mlx_put_image_to_window(sys->mlx, sys->mlx_win, raycst.frame.img, 0, 0);
	mlx_put_image_to_window(sys->mlx, sys->mlx_win, raycst.minimap.img, 0, 0);
	mlx_put_image_to_window(sys->mlx, sys->mlx_win, raycst.playermini.img,
		((MPSIZE * MSIZE) / 2) - MPLAYERSIZE / 2, ((MPSIZE * MSIZE) / 2)
		- MPLAYERSIZE / 2);
	return (reset_image(&raycst, sys));
}
