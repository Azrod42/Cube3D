/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:02:50 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/15 14:38:39 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	fix_dpre(char **file, int mapl);
int	i_line(char **map_t, char *st, int mapl);
int	is_mapline(char **map);
int	verifmapf(char **map, int mapl, int i);

char	**error(char **map_t, t_system *sys)
{
	free_char_tab(map_t);
	printf("Error in map format\n");
	return (NULL);
	(void)sys;
}

char	*strpud(char *str)
{
	int		i;
	int		s;
	char	*dup;

	i = 0;
	s = ft_strlen(str);
	dup = ft_calloc(s + 1, sizeof(char));
	while (i < s)
	{
		dup[i] = str[i];
		i++;
	}
	dup[s] = 0;
	return (dup);
}

void	tgmlp(t_system *sys, char **map_t, int m, int i)
{
	while (map_t[m])
	{
		sys->map[8 + i] = strpud(map_t[m]);
		m++;
		i++;
	}
	sys->map[8 + i] = 0;
}

int	initialize1(int t, t_system *sys, int mapl, char **map_t)
{
	t = i_line(map_t, "WE", mapl);
	if (t == -1)
		return (-1);
	sys->map[2] = strpud(map_t[t]);
	t = i_line(map_t, "EA", mapl);
	if (t == -1)
		return (-1);
	sys->map[3] = strpud(map_t[t]);
	sys->map[4] = ft_strdup("");
	t = i_line(map_t, "F ", mapl);
	if (t == -1)
		return (-1);
	sys->map[5] = strpud(map_t[t]);
	t = i_line(map_t, "C ", mapl);
	if (t == -1)
		return (-1);
	sys->map[6] = strpud(map_t[t]);
	sys->map[7] = ft_strdup("");
	return (0);
}

char	**fixing(char	*buf, t_system *sys, char **map_t, int i)
{
	int	mapl;
	int	t;

	map_t = ft_split_cb(buf, '\n');
	mapl = is_mapline(map_t);
	if (verifmapf(map_t, mapl, -1) == 1)
		return (error(map_t, sys));
	if (fix_dpre(map_t, mapl) == -1)
		return (error(map_t, sys));
	while (map_t[i])
		i++;
	sys->map = ft_calloc(i + 100, sizeof(char *));
	t = i_line(map_t, "NO", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[0] = strpud(map_t[t]);
	t = i_line(map_t, "SO", mapl);
	if (t == -1)
		return (error(map_t, sys));
	sys->map[1] = strpud(map_t[t]);
	if (initialize1(0, sys, mapl, map_t) == -1)
		return (error(map_t, sys));
	tgmlp(sys, map_t, mapl, 0);
	free_char_tab(map_t);
	return (sys->map);
}
