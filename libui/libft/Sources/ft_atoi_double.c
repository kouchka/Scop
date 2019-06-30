/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:41:47 by jlehideu          #+#    #+#             */
/*   Updated: 2019/01/08 16:01:04 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_atoi_double_2(char const *str, double *nb, int i)
{
	double	coma;

	coma = 0.1;
	if (str[i] && str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		*nb = *nb + coma * (str[i] - 48);
		i++;
		coma *= 0.1;
	}
}

double		ft_atoi_double(char const *str)
{
	int		i;
	int		signe;
	double	nb;

	nb = 0;
	signe = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	ft_atoi_double_2(str, &nb, i);
	if (signe == -1)
		nb = nb * (-1);
	return (nb);
}
