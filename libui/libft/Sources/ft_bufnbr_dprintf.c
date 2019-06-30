/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bufnbr_dprintf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 20:27:23 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:57 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bufnbr_dprintf(long long int n, t_pfspe *point)
{
	if (n == 0 && point->plus > 0 && point->size_content == 1)
		return ;
	(n > 9 || n < -9) ? ft_bufnbr_dprintf(n / 10, point) : 0;
	(n > 0) ? ft_check_dbuffer(point, (n % 10) + 48) :
		ft_check_dbuffer(point, (-1 * (n % 10) + 48));
}
