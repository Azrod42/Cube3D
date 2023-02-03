/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:22 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/11 10:48:54 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	verif_mapfile_name(t_system *sys);

int	error_return_map_format(int r)
{
	if (r == 0)
		printf("Use a correct file format\n");
	else if (r == 1)
		printf("Error while opening NO file\n");
	else if (r == 2)
		printf("Error while opening SO file\n");
	else if (r == 3)
		printf("Error while opening WE file\n");
	else if (r == 4)
		printf("Error while opening EA file\n");
	return (-1);
}

int	verif_format_no(t_system *sys)
{
	int		len;
	int		fd;
	int		r;
	char	*file;

	r = 0;
	len = ft_strlen_cb(sys->map[0]);
	if (len < 5)
		r = -1;
	else if (sys->map[0][0] != 'N')
		r = -1;
	else if (sys->map[0][1] != 'O')
		r = -1;
	else if (sys->map[0][2] != ' ')
		r = -1;
	if (r == -1)
		return (error_return_map_format(0));
	file = ft_strtrim_cb(sys->map[0], "NO ");
	fd = open(file, O_RDONLY);
	free (file);
	if (fd == -1)
		return (error_return_map_format(1));
	close (fd);
	return (0);
}

int	verif_format_so(t_system *sys)
{
	int		len;
	int		r;
	int		fd;
	char	*file;

	r = 0;
	len = ft_strlen_cb(sys->map[1]);
	if (len < 5)
		r = -1;
	else if (sys->map[1][0] != 'S')
		r = -1;
	else if (sys->map[1][1] != 'O')
		r = -1;
	else if (sys->map[1][2] != ' ')
		r = -1;
	if (r == -1)
		return (error_return_map_format(0));
	file = ft_strtrim_cb(sys->map[1], "SO ");
	fd = open(file, O_RDONLY);
	free (file);
	if (fd == -1)
		return (error_return_map_format(2));
	close (fd);
	return (0);
}

int	verif_format_we(t_system *sys)
{
	int		len;
	int		r;
	int		fd;
	char	*file;

	r = 0;
	len = ft_strlen_cb(sys->map[2]);
	if (len < 5)
		r = -1;
	else if (sys->map[2][0] != 'W')
		r = -1;
	else if (sys->map[2][1] != 'E')
		r = -1;
	else if (sys->map[2][2] != ' ')
		r = -1;
	if (r == -1)
		return (error_return_map_format(0));
	file = ft_strtrim_cb(sys->map[2], "WE ");
	fd = open(file, O_RDONLY);
	free (file);
	if (fd == -1)
		return (error_return_map_format(3));
	close (fd);
	return (0);
}

int	verif_format_ea(t_system *sys)
{
	int		len;
	int		r;
	int		fd;
	char	*file;

	r = 0;
	len = ft_strlen_cb(sys->map[3]);
	if (len < 5)
		r = -1;
	else if (sys->map[3][0] != 'E')
		r = -1;
	else if (sys->map[3][1] != 'A')
		r = -1;
	else if (sys->map[3][2] != ' ')
		r = -1;
	if (r == -1)
		return (error_return_map_format(0));
	file = ft_strtrim_cb(sys->map[3], "EA ");
	fd = open(file, O_RDONLY);
	free (file);
	if (fd == -1)
		return (error_return_map_format(4));
	close (fd);
	return (0);
}
