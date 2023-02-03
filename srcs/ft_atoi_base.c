/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <lfantine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:51:13 by lfantine          #+#    #+#             */
/*   Updated: 2023/02/02 09:30:45 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_inbase(char *str, char *base);

char	*ft_checkmeno(char *str, int *nb)
{
	*nb = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*nb += 1;
		str++;
	}
	if (*nb % 2 > 0)
		*nb = 1;
	else
		*nb = 0;
	return (str);
}

int	ft_calc_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (base[j])
		{
			if (i != j && base[i] == base[j])
				return (0);
			if (base[j] == '+' || base[j] == '-')
				return (0);
			if (base[j] >= 9 && base[j] <= 13)
				return (0);
			if (base[j] == ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_str_inbase(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (*str == base[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_backvalue(char *str, int tbase, int *res, char *base)
{
	int	i;

	i = 0;
	while (ft_str_inbase(str, base) == 1)
	{
		*res *= tbase;
		while (base[i])
		{
			if (base[i] == *str)
			{
				*res += i;
			}
			i++;
		}
		i = 0;
		str++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	meno;
	int	tbase;
	int	i;

	res = 0;
	str = ft_checkmeno(str, &meno);
	tbase = ft_calc_base(base);
	i = 0;
	if (tbase < 2)
		return (0);
	ft_backvalue(str, tbase, &res, base);
	if (meno == 1)
		res *= -1;
	return (res);
}
