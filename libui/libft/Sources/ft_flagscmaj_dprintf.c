/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagscmaj_dprintf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 14:37:39 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:20 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_useflags(t_pfspe *p, int32_t address)
{
	char c;

	ft_flag_zero_dprintf(&c, p);
	if (p->minus > 0)
	{
		ft_dprintfcmaj(p, address);
		ft_put_dfield(p, c);
	}
	else
	{
		ft_put_dfield(p, c);
		ft_dprintfcmaj(p, address);
	}
}

void		ft_flagscmaj_dprintf(t_pfspe *p, int32_t ca)
{
	if (ca >= 0 && ca <= 127)
		p->field -= 1;
	else if (ca >= 128 && ca <= 2047)
		p->field -= 2;
	else if (ca >= 2048 && ca <= 65535)
		p->field -= 3;
	else if (ca >= 65536 && ca <= 2097151)
		p->field -= 4;
	ft_useflags(p, ca);
}
