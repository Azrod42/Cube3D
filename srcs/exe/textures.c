/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:12 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 15:33:55 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	*malloced(char *p);

int	init_cf_texture2(t_system *sys, int x, int y, int i)
{
	char	*color;
	char	*temp;

	y = 0;
	color = 0;
	while (sys->map[x][y])
	{
		if (ft_isdigit(sys->map[x][y]))
		{
			if (color)
				temp = color;
			else
				temp = malloced(temp);
			color = ft_strjoin_cub(temp,
					ft_itoa_base_cub(ft_atoi(&sys->map[x][y]), 2));
			while (ft_isdigit(sys->map[x][y]))
				y++;
		}
		else
			y++;
	}
	sys->back_color[i] = ft_atoi_base(color, "0123456789ABCDEF");
	free(color);
	return (0);
}

int	init_cf_texture(t_system *sys, int x, int y)
{
	while (sys->map[x])
	{
		if (sys->map[x][0] == 'F')
		{
			init_cf_texture2(sys, x, y, 0);
		}
		if (sys->map[x][0] == 'C')
		{
			init_cf_texture2(sys, x, y, 1);
		}
		x++;
	}
	return (0);
}

int	init_texture3(t_system	*sys, int y, int x)
{
	while (++y < IMGS)
	{
		x = -1;
		while (++x < IMGS)
		{
			sys->txt->txts[0][IMGS * y + x] = *(int *)(sys->txt->no.addr
					+ (y * sys->txt->no.line_length
						+ x * (sys->txt->no.bits_per_pixel / 8)));
			sys->txt->txts[1][IMGS * y + x] = *(int *)(sys->txt->so.addr
					+ (y * sys->txt->so.line_length
						+ x * (sys->txt->so.bits_per_pixel / 8)));
			sys->txt->txts[2][IMGS * y + x] = *(int *)(sys->txt->we.addr
					+ (y * sys->txt->we.line_length
						+ x * (sys->txt->we.bits_per_pixel / 8)));
			sys->txt->txts[3][IMGS * y + x] = *(int *)(sys->txt->ea.addr
					+ (y * sys->txt->ea.line_length
						+ x * (sys->txt->ea.bits_per_pixel / 8)));
		}
	}
	return (0);
}

int	init_texture2(t_system	*sys)
{
	int	size;

	size = IMGS;
	sys->txt->no.img = mlx_xpm_file_to_image(sys->mlx,
			sys->txt->n_texture, &size, &size);
	sys->txt->so.img = mlx_xpm_file_to_image(sys->mlx,
			sys->txt->s_texture, &size, &size);
	sys->txt->we.img = mlx_xpm_file_to_image(sys->mlx,
			sys->txt->w_texture, &size, &size);
	sys->txt->ea.img = mlx_xpm_file_to_image(sys->mlx,
			sys->txt->e_texture, &size, &size);
	sys->txt->no.addr = mlx_get_data_addr(sys->txt->no.img,
			&sys->txt->no.bits_per_pixel, &sys->txt->no.line_length,
			&sys->txt->no.endian);
	sys->txt->so.addr = mlx_get_data_addr(sys->txt->so.img,
			&sys->txt->so.bits_per_pixel, &sys->txt->so.line_length,
			&sys->txt->so.endian);
	sys->txt->we.addr = mlx_get_data_addr(sys->txt->we.img,
			&sys->txt->we.bits_per_pixel, &sys->txt->we.line_length,
			&sys->txt->we.endian);
	sys->txt->ea.addr = mlx_get_data_addr(sys->txt->ea.img,
			&sys->txt->ea.bits_per_pixel, &sys->txt->ea.line_length,
			&sys->txt->ea.endian);
	return (0);
}

int	init_texture(t_system	*sys)
{
	int	y;

	sys->txt->n_texture = (ft_strtrim(sys->map[0], "NO "));
	sys->txt->s_texture = (ft_strtrim(sys->map[1], "SO "));
	sys->txt->w_texture = (ft_strtrim(sys->map[2], "WE "));
	sys->txt->e_texture = (ft_strtrim(sys->map[3], "EA "));
	y = -1;
	while (++y < 4)
	{
		sys->txt->txts[y] = malloc (sizeof (unsigned int *)
				* (IMGS * IMGS + 1));
		sys->txt->txts[y][IMGS * IMGS] = 0;
	}
	y = -1;
	init_texture2(sys);
	init_texture3(sys, -1, 0);
	return (init_cf_texture(sys, 0, 0));
}
