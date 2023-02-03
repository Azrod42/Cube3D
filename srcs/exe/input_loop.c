/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 14:56:56 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	walk(t_system *sys, double x, double y)
{
	if (sys->play_map[(int)sys->player->pos.y][(int)(sys->player->pos.x
		+ (x * SPEED))] != '1')
	{
		if (sys->play_map[(int)(sys->player->pos.y
				+ (y * SPEED))][(int)(sys->player->pos.x)] != '1')
		{
			sys->player->pos.x += (x * SPEED);
			sys->player->pos.y += (y * SPEED);
		}
		else
			sys->player->pos.x += (x * SPEED);
	}
	else if (sys->play_map[(int)(sys->player->pos.y
			+ (y * SPEED))][(int)(sys->player->pos.x)] != '1')
		sys->player->pos.y += (y * SPEED);
}

void	rotate(t_system *sys, int s)
{
	double	olddirx;
	double	oldplanex;

	oldplanex = sys->player->plane.x;
	olddirx = sys->player->rotation.x;
	sys->player->rotation.x = sys->player->rotation.x * cos(s * SENSI)
		- sys->player->rotation.y * sin(s * SENSI);
	sys->player->rotation.y = olddirx * sin(s * SENSI)
		+ sys->player->rotation.y * cos(s * SENSI);
	sys->player->plane.x = sys->player->plane.x * cos(s * SENSI)
		- sys->player->plane.y * sin(s * SENSI);
	sys->player->plane.y = oldplanex * sin(s * SENSI)
		+ sys->player->plane.y * cos(s * SENSI);
}

void	input_handler(t_system *sys)
{
	if (sys->input.b_back == 1 && sys->input.b_front == 0)
		walk(sys, -sys->player->rotation.x, -sys->player->rotation.y);
	if (sys->input.b_left == 1 && sys->input.b_right == 0)
		walk(sys, sys->player->rotation.y, -sys->player->rotation.x);
	if (sys->input.b_right == 1 && sys->input.b_left == 0)
		walk(sys, -sys->player->rotation.y, sys->player->rotation.x);
	if (sys->input.b_front == 1 && sys->input.b_back == 0)
		walk(sys, sys->player->rotation.x, sys->player->rotation.y);
	if (sys->input.b_rot_left == 1 && sys->input.b_rot_right == 0)
		rotate(sys, -1);
	if (sys->input.b_rot_right == 1 && sys->input.b_rot_left == 0)
		rotate(sys, 1);
}

int	ft_loop(t_system *sys)
{
	input_handler(sys);
	raycasting(sys, sys->player, 0);
	return (0);
}
