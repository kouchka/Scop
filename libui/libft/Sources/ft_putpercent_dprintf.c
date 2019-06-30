/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent_dprintf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:10:49 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fieldpercent(t_pfspe *point, char c)
{
	while (point->field > 0)
	{
		ft_check_dbuffer(point, c);
		point->field--;
	}
}

void		ft_putpercent_dprintf(t_pfspe *point)
{
	char c;

	c = ' ';
	point->precision = 0;
	point->point = 0;
	point->field -= 1;
	if (point->minus > 0)
	{
		ft_check_dbuffer(point, '%');
		ft_fieldpercent(point, c);
	}
	else
	{
		ft_flag_zero_dprintf(&c, point);
		ft_fieldpercent(point, c);
		ft_check_dbuffer(point, '%');
	}
}
