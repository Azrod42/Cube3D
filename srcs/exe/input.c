/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/03 09:12:07 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	key_down(int keycode, t_system *sys)
{
	if (keycode == 53)
	{
		free_all_cb(sys);
	}
	if (keycode == 1)
		sys->input.b_back = 1;
	if (keycode == 0)
		sys->input.b_left = 1;
	if (keycode == 2)
		sys->input.b_right = 1;
	if (keycode == 13)
		sys->input.b_front = 1;
	if (keycode == 123)
		sys->input.b_rot_left = 1;
	if (keycode == 124)
		sys->input.b_rot_right = 1;
	return (keycode);
}

int	key_up(int keycode, t_system *sys)
{
	if (keycode == 1)
		sys->input.b_back = 0;
	if (keycode == 0)
		sys->input.b_left = 0;
	if (keycode == 2)
		sys->input.b_right = 0;
	if (keycode == 13)
		sys->input.b_front = 0;
	if (keycode == 123)
		sys->input.b_rot_left = 0;
	if (keycode == 124)
		sys->input.b_rot_right = 0;
	return (keycode);
}

int	cross(t_system *sys)
{
	free_all_cb(sys);
	return (0);
}
