/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:02:50 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/11 14:39:08 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	i_line(char **map_t, char *st, int mapl)
{
	int	i;

	i = -1;
	while (map_t[++i] && i < mapl)
	{
		if (map_t[i][0] == st[0] && map_t[i][1] == st[1])
			return (i);
	}
	return (-1);
}

int	is_mapline(char **map)
{
	int	i;
	int	j;
	int	r;

	i = -1;
	while (map[++i])
	{
		j = -1;
		r = 0;
		while (map[i][++j] && r == 0)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
				r = 1;
			else
			{
				if (map[i][j + 1] != '\n')
					return (i);
			}
		}
	}
	return (-1);
}

char	**error(char **map_t, t_system *sys)
{
	free_char_tab(map_t);
	free_char_tab(sys->map);
	printf("Error in map format\n");
	return (NULL);
}

char	**fixing(char	*buf, t_system *sys, char **map_t, int i)
{
	int	mapl;
	int	t;

	map_t = ft_split_cb(buf, '\n');
	printf("test");
	mapl = is_mapline(map_t);
	while (map_t[i])
		i++;
	sys->map = malloc(sizeof(char *) * i);
	t = i_line(map_t, "NO", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[0] = ft_strdup(map_t[t]);
	t = i_line(map_t, "SO", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[1] = ft_strdup(map_t[t]);
	t = i_line(map_t, "WE", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[2] = ft_strdup(map_t[t]);
	t = i_line(map_t, "EA", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[3] = ft_strdup(map_t[t]);
	sys->map[4] = ft_strdup("\n");
	t = i_line(map_t, "F ", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[5] = ft_strdup(map_t[t]);
	t = i_line(map_t, "C ", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[6] = ft_strdup(map_t[t]);
	sys->map[7] = ft_strdup("\n");
	print_char_tab(sys->map);
	printf("end");
	return (map_t);
}