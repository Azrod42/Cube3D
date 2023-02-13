/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_blob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:22:00 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/13 12:20:39 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		blob_hub(char **map, t_pos p_pos);
t_pos	find_start_player(char **map);
int		blob_error(char	*str);

int	launch_blob(t_system *sys)
{
	char	**map;
	t_pos	p_pos;

	map = make_map(sys);
	p_pos = find_start_player(map);
	if (blob_hub(map, p_pos) == -1)
	{
		free_char_tab(map);
		return (-1);
	}
	free_char_tab(map);
	sys->play_map = make_map(sys);
	return (0);
}

int	finish_blob(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
			{
				if (map[i + 1][j] == '0')
					return (0);
				else if (map[i - 1][j] == '0')
					return (0);
				else if (map[i][j + 1] == '0')
					return (0);
				else if (map[i][j - 1] == '0')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	error_find(char **map, int ymax)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'M')
			{
				if (i + 1 >= ymax || map[i + 1][j] == ' ' || map[i + 1][j] == 0)
					return (-1);
				if (i - 1 < 0 || map[i - 1][j] == ' ' || map[i - 1][j] == 0)
					return (-1);
				if (j == 0 || map[i][j - 1] == ' ' || map[i][j - 1] == 0)
					return (-1);
				if (map[i][j + 1] == ' ' || map[i][j + 1] == 0)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	replace_char_blob(int i, int j, int ymax, char **map)
{
	while (map[i][j])
	{
		if (map[i][j] == 'M')
		{
			if (i + 1 < ymax && map[i + 1][j] == '0')
				map[i + 1][j] = 'M';
			if (i > 0 && map[i - 1][j] == '0')
				map[i - 1][j] = 'M';
			if (map[i][j + 1] == '0')
				map[i][j + 1] = 'M';
			if (j > 0 && map[i][j - 1] == '0')
				map[i][j - 1] = 'M';
		}
		j++;
	}
	return (0);
}

int	blob_hub(char **map, t_pos p_pos)
{
	int	i;
	int	ymax;

	i = 0;
	while (map[i])
		i++;
	ymax = i;
	i = 0;
	printf("%d | %d\n", p_pos.x, p_pos.y);
	map[p_pos.y][p_pos.x] = 'M';
	if (error_find(map, ymax) == -1)
		return (blob_error("Error with border"));
	while (finish_blob(map) == 0)
	{
		i = 0;
		while (map[i])
		{
			replace_char_blob(i, 0, ymax, map);
			i++;
		}
		if (error_find(map, ymax) == -1)
			return (blob_error("Error with border"));
	}
	return (0);
}
