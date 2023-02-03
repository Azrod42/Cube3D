/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:34:27 by lfantine          #+#    #+#             */
/*   Updated: 2023/01/11 10:52:37 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d.h"

void	make_tab_char(char *tab)
{
	tab[0] = '0';
	tab[1] = '1';
	tab[2] = 'N';
	tab[3] = 'S';
	tab[4] = 'E';
	tab[5] = 'W';
	tab[6] = ' ';
	tab[7] = 'T';
	tab[8] = 'P';
	tab[9] = 'F';
}

int	free_char_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

int	print_char_tab(char **tab)
{
	int	i;

	i = 0;
	printf("__________________________________\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("__________________________________\n\n");
	return (0);
}

int	ft_strlen_cb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
