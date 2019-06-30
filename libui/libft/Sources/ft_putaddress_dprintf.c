/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_dprintf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 17:11:03 by allallem          #+#    #+#             */
/*   Updated: 2019/04/22 19:23:10 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_field_address(t_pfspe *p)
{
	char c;

	ft_flag_zero_dprintf(&c, p);
	(c == 'p' || (c == 'X' && p->diese > 0) || (c == 'x' && p->diese > 0)) ?
		p->field -= 2 : 0;
	while (p->field > 0)
	{
		ft_check_dbuffer(p, c);
		p->field--;
	}
}

static void		ft_preci_cpy_address(t_pfspe *p, char *str)
{
	int j;

	j = 0;
	while (p->precision > 0)
	{
		ft_check_dbuffer(p, '0');
		p->precision--;
	}
	while (str[j])
	{
		ft_check_dbuffer(p, str[j]);
		j++;
	}
}

static void		ft_checkflags_address(t_pfspe *p, char *str, char c)
{
	ft_calculate_address_dprintf(p, str, c);
	if (p->minus > 0)
	{
		ft_adjustaddress_dprintf(p, c, str);
		ft_preci_cpy_address(p, str);
		ft_field_address(p);
	}
	else if ((p->zero > 0 && p->diese > 0) || (c == 'p' && p->zero > 0))
	{
		ft_adjustaddress_dprintf(p, c, str);
		ft_field_address(p);
		ft_preci_cpy_address(p, str);
	}
	else
	{
		ft_field_address(p);
		ft_adjustaddress_dprintf(p, c, str);
		ft_preci_cpy_address(p, str);
	}
}

static void		ft_print(char *result, int compteur, char c, t_pfspe *point)
{
	int j;

	if (c == 'X')
	{
		j = compteur;
		while (result[j])
		{
			(result[j] >= 'a' && result[j] <= 'z') ?
				result[j] = ft_toupper(result[j]) : 0;
			j++;
		}
		ft_checkflags_address(point, result + compteur, c);
	}
	else
		ft_checkflags_address(point, result + compteur, c);
}

void			ft_putaddress_dprintf(void *addres, char c, t_pfspe *p,
	int base)
{
	unsigned long long int	nbr;
	int						compteur;
	char					*str;
	char					result[67];

	ft_typefor_address(p, addres, &nbr, c);
	compteur = 66;
	if (!ft_special_address_dprintf(nbr, c, p))
		return ;
	str = "0123456789abcdefghijklmnopqrstuvwxyz";
	result[compteur] = '\0';
	while (nbr > 0)
	{
		compteur--;
		result[compteur] = str[nbr % base];
		nbr /= base;
	}
	ft_print(result, compteur, c, p);
}
