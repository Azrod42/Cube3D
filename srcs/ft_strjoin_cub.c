/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_cub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:42:16 by tsorabel          #+#    #+#             */
/*   Updated: 2023/02/25 11:26:13 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*ft_strjoin_cub(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	if (!s1 || !s2)
		return (NULL);
	dup = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dup[i] = s1[i];
	i--;
	while (s2[++j])
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (dup);
}

int	prepre(char **s, int ln)
{
	int	i;
	int	bc;

	i = 0;
	bc = -1;
	while (s[ln][i] && (s[ln][++i] == 32 || (s[ln][i] >= 9 && s[ln][i] <= 13)))
		;
	while (++bc < 3)
	{
		while (s[ln][i] && s[ln][i] == 32)
			i++;	
		if ((s[ln][i] < '0' || s[ln][i] > '9'))
		{
			printf("Invalid RGB\n");
			return (-1);
		}
		while (s[ln][++i] && s[ln][i] != ',')
			;
		if (s[ln][i] == ',')
			i++;
	}
	return (0);
}
