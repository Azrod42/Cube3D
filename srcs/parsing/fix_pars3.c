/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_pars3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:02:50 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/25 11:59:43 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

char	*letrim(char *str)
{
	char	*tmp;

	tmp = str;
	str = ft_strtrim(str, " ");
	free(tmp);
	return (str);
}

char	**alloftrim(char **file)
{
	file[0] = letrim(file[0]);
	file[1] = letrim(file[1]);
	file[2] = letrim(file[2]);
	file[3] = letrim(file[3]);
	file[5] = letrim(file[5]);
	file[6] = letrim(file[6]);
	print_char_tab(file);
	return (file);
}

char	**lesplit(char *buf, int i)
{
	while (buf[i] == '\n')
		i++;
	return (ft_split_cb(&buf[i], '\n'));
}
