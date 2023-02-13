/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:42:03 by tsorabel          #+#    #+#             */
/*   Updated: 2023/02/13 15:12:12 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

char	*ft_strdup(char const *s)
{
	char	*dup;

	dup = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
	{
		printf("dup fail\n !");
		return (NULL);
	}
	ft_memcpy(dup, s, ft_strlen(s));
	dup[ft_strlen(s)] = '\0';
	return (dup);
}
