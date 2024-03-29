/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_spe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:59:50 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:10:01 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_init_pfspe(t_pfspe *point)
{
	point->h = 0;
	point->l = 0;
	point->j = 0;
	point->z = 0;
	point->diese = 0;
	point->zero = 0;
	point->minus = 0;
	point->plus = 0;
	point->space = 0;
	point->point = 0;
	point->result = 0;
	point->field = 0;
	point->precision = 0;
	point->size_content = 0;
}

static int		ft_check_param(char c, t_pfspe *point)
{
	if (c == 'd' || c == 'i' || c == 'D')
		ft_dprintfdi(c, point, va_arg(point->ap, intmax_t));
	else if (c == 's' && point->l != 1)
		ft_dprintfs(point, va_arg(point->ap, char*));
	else if (c == 'p' || c == 'x' || c == 'X')
		ft_putaddress_dprintf(va_arg(point->ap, void*), c, point, 16);
	else if (c == 'c' && point->l != 1)
		ft_dprintf_c(point, va_arg(point->ap, int));
	else if (c == 'o' || c == 'O')
		ft_putaddress_dprintf(va_arg(point->ap, void*), c, point, 8);
	else if (c == '%')
		ft_putpercent_dprintf(point);
	else if (c == 'u' || c == 'U')
		ft_putaddress_dprintf(va_arg(point->ap, void*), c, point, 10);
	else if (c == 'C' || (c == 'c' && point->l == 1))
		ft_flagscmaj_dprintf(point, va_arg(point->ap, int32_t));
	else if (c == 'S' || (c == 's' && point->l == 1))
		ft_flagssmaj(point, va_arg(point->ap, void*));
	else if (c == '\0')
		return (0);
	else if (c == 'b')
		ft_putaddress_dprintf(va_arg(point->ap, void*), c, point, 2);
	else
		ft_dprintf_c(point, c);
	return (1);
}

int				ft_dprintf_spe(char const *str, t_pfspe *point)
{
	int i;

	ft_init_pfspe(point);
	i = 0;
	i = ft_fillstruct_printf(point, str);
	ft_check_param(str[i], point);
	return (point->result);
}
