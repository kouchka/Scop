/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:53:36 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:59 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_c_field(t_pfspe *point)
{
	char c;

	(point->zero > 0 && point->precision == 0 && point->minus == 0) ? c = '0'
		: (c = ' ');
	while (point->field > 0)
	{
		ft_check_dbuffer(point, c);
		point->field--;
	}
}

void		ft_dprintf_c(t_pfspe *point, unsigned char c)
{
	point->field--;
	if (point->minus == 0)
	{
		ft_put_c_field(point);
		ft_check_dbuffer(point, c);
	}
	else
	{
		ft_check_dbuffer(point, c);
		ft_put_c_field(point);
	}
}
