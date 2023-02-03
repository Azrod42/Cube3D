/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hub3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:19 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/11 10:47:51 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int		search_start_pos(char **map);
int		launch_blob(t_system *sys);

int	pars_hub3(t_system *sys)
{
	if (search_start_pos(sys->map) == -1)
		return (-1);
	if (launch_blob(sys) == -1)
		return (-1);
	return (0);
}

int	search_start_pos(char **map)
{
	int	i;
	int	j;
	int	nb_pos;

	i = 0;
	nb_pos = 0;
	while (map[8 + i])
	{
		j = 0;
		while (map[8 + i][j])
		{
			if (map[8 + i][j] == 'N' || map[8 + i][j] == 'S' ||
					map[8 + i][j] == 'W' || map[8 + i][j] == 'E')
				nb_pos++;
			j++;
		}
		i++;
	}
	if (nb_pos == 0)
		printf("The player need a start position\n");
	else if (nb_pos > 1)
		printf("The player need only ONE start position\n");
	if (nb_pos == 0 || nb_pos > 1)
		return (-1);
	return (0);
}

char	**make_map(t_system *sys)
{
	int		i;
	char	**map;

	i = 0;
	while (sys->map[8 + i])
		i++;
	map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (sys->map[8 + i])
	{
		map[i] = ft_strdup_cb(sys->map[8 + i]);
		i++;
	}
	map[i] = NULL;
	return (map);
}
