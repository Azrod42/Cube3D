/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit-free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:12:47 by tsorabel          #+#    #+#             */
/*   Updated: 2023/02/25 13:35:27 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_all_cb(t_system *sys)
{
	sys->end = 1;
	exit(0);
}

char	*malloced(char *p)
{
	p = malloc (sizeof(char));
	p[0] = 0;
	return (p);
}

char	*remove_nl(char *str)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	j = 0;
	new = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	while (str[++i])
	{
		if (i > 0 && str[i] == '\n' && str[i - 1] == '\n' && str[i - 2] == '\n')
		{
			while (str[++i] == '\n')
				;
			i--;
		}
		else
		{
			new[j] = str[i];
			j++;
		}
	}
	new[i] = '\0';
	free(str);
	return (new);
}

int	comapc(char **s, int ln, int *comac, int i)
{
	while (s[ln][++i])
		if (s[ln][i] == ',')
			*comac += 1;
	if (*comac != 2)
	{
		printf("Invalid RGB\n");
		return (-1);
	}
	return (0);
}

int	precheck(char **s, int ln, int comac)
{
	int	i;

	if (comapc(s, ln, &comac, 0) == -1 || prepre(s, ln) == -1)
		return (-1);
	i = 0;
	while (s[ln][i] && (s[ln][++i] == 32 || (s[ln][i] >= 9 && s[ln][i] <= 13)))
		;
	while (s[ln][i])
	{	
		while (s[ln][i] && s[ln][i] == ' ')
			i++;
		while (s[ln][i] && s[ln][i] >= '0' && s[ln][i] <= '9')
			i++;
		if (s[ln][i] != ',' && s[ln][i] != '\0')
		{
			printf("Invalid RGB\n");
			return (-1);
		}
		if (s[ln][i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
