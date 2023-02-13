/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit-free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:12:47 by tsorabel          #+#    #+#             */
/*   Updated: 2023/02/13 17:34:52 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	free_all_cb(t_system *sys)
{
	sys->end = 1;
	system("leaks cub3D");
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

int	precheck(char **s, int ln, int comac)
{
	int	i;

	i = 0;
	while (s[ln][++i])
		if (s[ln][i] == ',')
			comac++;
	if (comac != 2)
	{
		printf("Invalid RGB\n");
		return (-1);
	}
	i = 0;
	while (s[ln][i] && (s[ln][++i] == 32 || (s[ln][i] >= 9 && s[ln][i] <= 13)))
		;
	while (s[ln][i])
	{	
		while (s[ln][i] && s[ln][i] == ' ')
			i++;
		while (s[ln][i] && s[ln][i] >= '0' && s[ln][i] <= '9')
			i++;
		printf("%c\n", s[ln][i]);
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

int	check_rgb(char **s, int ln, int count, int comac)
{
	int	i;
	int	nb;

	i = 0;
	print_char_tab(s);
	if (precheck(s, ln, 0) == -1)
		return (-1);
	while (s[ln][++i] == 32 || (s[ln][i] >= 9 && s[ln][i] <= 13))
		;
	nb = ft_atoi(&s[ln][i--]);
	while (s[ln][++i])
	{
		if ((s[ln][i] >= '0' && s[ln][i] <= '9') || s[ln][i] == 32)
			count++;
		if (s[ln][i] == ',')
		{
			count = 0;
			comac++;
			nb = ft_atoi(&s[ln][i + 1]);
		}
		if (count > 3 || comac > 3 || ((s[ln][i] < '0' || nb < 0
				|| s[ln][i] > '9') && s[ln][i] != ',' && s[ln][i] != ' ') || nb > 255)
		{
			printf("Invalid RGB\n");
			return (-1);
		}
	}
	return (0);
}
