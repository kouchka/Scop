/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_dprintf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:59:46 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:37 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_dprintf(char const *str, t_pfspe *p)
{
	int		i;
	char	*nul;

	nul = "(null)";
	i = 0;
	if (!str)
	{
		while (nul[i])
		{
			ft_check_dbuffer(p, nul[i]);
			i++;
		}
		return ;
	}
	while (str[i])
	{
		ft_check_dbuffer(p, str[i]);
		i++;
	}
}
