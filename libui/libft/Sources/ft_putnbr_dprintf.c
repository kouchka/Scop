/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_dprintf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:40:44 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:29 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_dprintf(long long int n, t_pfspe *point)
{
	if (n < 0)
	{
		ft_check_dbuffer(point, '-');
		n = n * (-1);
	}
	(n > 9) ? ft_putnbr_dprintf(n / 10, point) : 0;
	ft_check_dbuffer(point, (n % 10) + 48);
}
