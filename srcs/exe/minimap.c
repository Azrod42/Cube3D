/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:34:00 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 17:19:11 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	printtab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		printf("%s\n", tab[i]);
}

void	init_minimap(t_system *sys, int i, int j, int k)
{
	char	*temp;

	while (sys->play_map[++i])
		;
	sys->minimap = malloc(sizeof(char *) * ((i * MSIZE) + 2));
	i = -1;
	while (sys->play_map[++i])
	{
		j = -1;
		while (sys->play_map[i][++j])
			;
		temp = malloc(sizeof(char) * ((j * MSIZE) + 1));
		j = -1;
		while (sys->play_map[i][++j])
		{
			k = -1;
			while (++k < MSIZE)
				temp[(j * MSIZE) + k] = sys->play_map[i][j];
			temp[(j * MSIZE) + k] = '\0';
		}
		k = -1;
		while (++k < MSIZE)
			sys->minimap[(i * MSIZE) + k] = temp;
	}
	sys->minimap[(i * MSIZE) + 0] = NULL;
}

int	print_mini2(t_system *sys, int posox, int posoy, t_pos *pos)
{
	t_line	line;

	if (sys->minimap[pos->y][pos->x] == '1')
	{
		line.color = MWALLCOLOR;
		line.drawend = pos->y - posoy + 1;
		line.drawstart = pos->y - posoy;
	}
	else
	{
		line.color = MOTHERCOLOR;
		line.drawend = pos->y - posoy + 1;
		line.drawstart = pos->y - posoy;
	}
	line.ipix = pos->x - posox;
	draw_line(line, sys->frame);
	return (1);
}

void	print_mini(t_data *frame, t_system *sys, int posox, int posoy)
{
	t_pos	pos;
	int		exit;

	sys->frame = frame;
	pos.y = (sys->player->pos.y * MSIZE) - ((MPSIZE / 2) * MSIZE);
	posoy = pos.y;
	posox = (sys->player->pos.x * MSIZE) - ((MPSIZE / 2) * MSIZE);
	exit = 0;
	if (pos.y < 0)
		pos.y = 0;
	while (sys->minimap[pos.y] && pos.y < (int)((sys->player->pos.y
			* MSIZE) + ((MPSIZE / 2) * MSIZE)))
	{
		pos.x = (sys->player->pos.x * MSIZE) - ((MPSIZE / 2) * MSIZE);
		if (pos.x < 0)
			pos.x = 0;
		while (sys->minimap[pos.y][pos.x] && pos.x <
				(int)((sys->player->pos.x * MSIZE) + ((MPSIZE / 2) * MSIZE)))
			pos.x += print_mini2(sys, posox, posoy, &pos);
		pos.y++;
	}
}

void	draw_player(t_data *player)
{
	int		i;
	t_line	line;

	i = 0;
	line.color = MPLAYERCOLOR;
	line.drawend = 10;
	line.drawstart = 1;
	while (i < MPLAYERSIZE)
	{
		line.ipix = i;
		draw_line(line, player);
		i++;
	}
}
