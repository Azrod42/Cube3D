/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_hub2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:17 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/11 10:53:10 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	verif_mapfile_name(t_system *sys);
int	verif_all_xml(t_system *sys);

int	pars_hub2(t_system *sys, int s)
{
	if (s == 1)
	{
		if (verif_mapfile_name(sys) == -1)
			return (-1);
	}
	else if (s == 2)
	{
		if (verif_format_no(sys) == -1)
			return (-1);
		if (verif_format_so(sys) == -1)
			return (-1);
		if (verif_format_we(sys) == -1)
			return (-1);
		if (verif_format_ea(sys) == -1)
			return (-1);
		if (verif_all_xml(sys) == -1)
			return (-1);
	}
	return (0);
}

int	verif_mapfile_name(t_system *sys)
{
	int	len;
	int	r;

	r = 0;
	len = ft_strlen_cb(sys->mapfile);
	if (sys->mapfile[len - 1] != 'b')
		r = -1;
	else if (sys->mapfile[len - 2] != 'u')
		r = -1;
	else if (sys->mapfile[len - 3] != 'c')
		r = -1;
	else if (sys->mapfile[len - 4] != '.')
		r = -1;
	if (r == -1)
	{
		printf("Use a correct file : [name of file][.cub]\n");
		return (-1);
	}
	return (0);
}

int	verif_mapfile_format(t_system *sys)
{
	int	len;
	int	r;

	r = 0;
	len = ft_strlen_cb(sys->mapfile);
	if (sys->mapfile[len - 1] != 'b')
		r = -1;
	else if (sys->mapfile[len - 2] != 'u')
		r = -1;
	else if (sys->mapfile[len - 3] != 'c')
		r = -1;
	else if (sys->mapfile[len - 4] != '.')
		r = -1;
	if (r == -1)
	{
		printf("Use a correct file : [name of file][.cub]\n");
		return (-1);
	}
	return (0);
}
