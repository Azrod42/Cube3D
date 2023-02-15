/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:42 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/15 14:39:15 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	main(int argc, char **argv)
{
	t_system	sys;
	t_texture	txt;

	sys.argc = argc;
	sys.argv = argv;
	sys.mapfile = argv[1];
	make_tab_char(sys.sprite);
	if (pars_hub(&sys) == -1)
	{
		return (-1);
	}
	sys.txt = &txt;
	exe_hub(&sys);
	return (0);
}
