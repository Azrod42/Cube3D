/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_check2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:25 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/03 07:59:45 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

int	verif_xml(char *file);

int	error_return_xml(int r)
{
	if (r == 0)
		printf("\n");
	else if (r == 1)
		printf("NO file need to be an xml file\n");
	else if (r == 2)
		printf("SO file need to be an xml file\n");
	else if (r == 3)
		printf("WE file need to be an xml file\n");
	else if (r == 4)
		printf("EA file need to be an xml file\n");
	return (-1);
}

int	verif_all_xml(t_system *sys)
{
	int	i;

	i = 0;
	if (verif_xml(sys->map[0]) == -1)
		return (error_return_xml(1));
	else if (verif_xml(sys->map[1]) == -1)
		return (error_return_xml(2));
	else if (verif_xml(sys->map[2]) == -1)
		return (error_return_xml(3));
	else if (verif_xml(sys->map[3]) == -1)
		return (error_return_xml(4));
	else if (sys->map[4][0] != 0)
	{
		printf("line 5 need to be empty\n");
		return (-1);
	}
	else if (sys->map[7][0] != 0)
	{
		printf("line 8 need to be empty\n");
		return (-1);
	}
	return (0);
}

int	verif_xml(char *file)
{
	int	len;
	int	r;

	r = 0;
	len = ft_strlen_cb(file);
	if (file[len - 1] != 'm')
		r = -1;
	else if (file[len - 2] != 'p')
		r = -1;
	else if (file[len - 3] != 'x')
		r = -1;
	else if (file[len - 4] != '.')
		r = -1;
	if (r == -1)
		return (-1);
	return (0);
}
