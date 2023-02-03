/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_hub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/03 08:44:34 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	checkraytouch(t_posd raydir, t_system *sys, t_player *player, int ipix);
int	key_down(int keycode, t_system *sys);
int	key_up(int keycode, t_system *sys);
int	ft_loop(t_system *sys);
int	init_texture(t_system	*sys);
int	cross(t_system *sys);

void	eipp2(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir = 270;
		player->plane.x = 0.66;
		player->plane.y = 0;
	}
	else if (c == 'E')
	{
		player->dir = 0;
		player->plane.x = 0;
		player->plane.y = 0.66;
	}
	else if (c == 'S')
	{
		player->dir = 90;
		player->plane.x = -0.66;
		player->plane.y = 0;
	}
	else if (c == 'W')
	{
		player->dir = 180;
		player->plane.x = 0;
		player->plane.y = -0.66;
	}
}

void	enter_init_player_pos(t_player *player, int x, int y, char c)
{
	double	radian;

	player->case_pos.x = x;
	player->case_pos.y = y;
	eipp2(player, c);
	player->pos.x = player->case_pos.x + 0.5;
	player->pos.y = player->case_pos.y + 0.5;
	radian = player->dir * (M_PI / 180);
	player->rotation.x = cos(radian);
	player->rotation.y = sin(radian);
}

void	init_player(t_player *player, char **map, t_system *sys)
{
	int	x;
	int	z;

	player->case_pos.y = 0;
	x = 0;
	while (map[x])
	{
		z = 0;
		while (map[x][z])
		{
			if (map[x][z] == 'N' || map[x][z] == 'E'
				|| map[x][z] == 'S' || map[x][z] == 'W')
				enter_init_player_pos(player, z, x, map[x][z]);
			z++;
		}
		x++;
	}
	sys->sizex = z;
	sys->sizey = x;
	sys->init_ok = 0;
}

int	exe_hub(t_system *sys)
{
	t_player	player;

	init_player(&player, sys->play_map, sys);
	sys->mlx = mlx_init();
	sys->player = &player;
	sys->mlx_win = mlx_new_window(sys->mlx, WIDTH, HEIGTH, "Cub5G");
	sys->end = 0;
	init_texture(sys);
	raycasting(sys, &player, 0);
	sys->front = 0;
	sys->rotate = 0;
	mlx_hook(sys->mlx_win, 2, (1L << 0), key_down, sys);
	mlx_hook(sys->mlx_win, 3, (1L << 0), key_up, sys);
	mlx_hook(sys->mlx_win, 17, (1L << 17), cross, sys);
	mlx_loop_hook(sys->mlx, ft_loop, sys);
	mlx_loop(sys->mlx);
	return (1);
}
