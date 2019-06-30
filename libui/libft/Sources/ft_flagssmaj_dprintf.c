/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagssmaj_dprintf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 15:17:01 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:23 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_useflags_s(t_pfspe *p, int32_t *str)
{
	char	c;
	int		i;

	i = 0;
	ft_flag_zero_dprintf(&c, p);
	if (p->minus > 0)
	{
		while (str[i])
		{
			ft_dprintfcmaj(p, str[i]);
			i++;
		}
		ft_put_dfield(p, c);
	}
	else
	{
		ft_put_dfield(p, c);
		while (str[i])
		{
			ft_dprintfcmaj(p, str[i]);
			i++;
		}
	}
}

static int			ft_adjustfield_s(int32_t ca)
{
	if (ca >= 0 && ca <= 127)
		return (-1);
	else if (ca >= 128 && ca <= 2047)
		return (-2);
	else if (ca >= 2048 && ca <= 65535)
		return (-3);
	else if (ca >= 65536 && ca <= 2097151)
		return (-4);
	return (0);
}

static void			ft_part_three(t_pfspe *p, int i, int j, int32_t *str)
{
	char c;

	ft_flag_zero_dprintf(&c, p);
	if (p->minus > 0)
	{
		while (j < i)
		{
			ft_dprintfcmaj(p, str[j]);
			j++;
		}
		if (p->field > 0)
			ft_put_dfield(p, c);
	}
	else
	{
		if (p->field > 0)
			ft_put_dfield(p, c);
		while (j < i)
		{
			ft_dprintfcmaj(p, str[j]);
			j++;
		}
	}
}

static void			ft_part_two(t_pfspe *p, int32_t *str, int i, int n)
{
	int j;

	j = 0;
	(n > p->precision) ? i-- : 0;
	if (p->point > 0)
		ft_part_three(p, i, j, str);
	else
	{
		i = 0;
		while (str[i])
		{
			p->field += ft_adjustfield_s(str[i]);
			i++;
		}
		ft_useflags_s(p, str);
	}
}

void				ft_flagssmaj(t_pfspe *p, void *address)
{
	int		i;
	int		n;
	int32_t	*str;

	n = 0;
	i = 0;
	if (address == NULL)
	{
		ft_putstr_dprintf("(null)", p);
		return ;
	}
	str = (int32_t*)address;
	if (p->point > 0)
	{
		while (str[i] && n < p->precision)
		{
			n = n - ft_adjustfield_s(str[i]);
			i++;
		}
		(n > p->precision) ? p->field = p->field
		- n - ft_adjustfield_s(str[i - 1]) : (p->field -= p->precision);
	}
	ft_part_two(p, str, i, n);
}
