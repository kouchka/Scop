/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintfs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:47:32 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:10:14 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_copy_in_buffer(t_pfspe *point, char *content)
{
	int i;

	i = 0;
	while (content[i])
	{
		ft_check_dbuffer(point, content[i]);
		i++;
	}
}

void			ft_flag_zero_dprintf(char *c, t_pfspe *point)
{
	(point->zero > 0 && point->minus == 0 && point->precision <= 0) ? *c = '0'
		: (*c = ' ');
}

void			ft_put_dfield(t_pfspe *point, char c)
{
	while (point->field > 0)
	{
		ft_check_dbuffer(point, c);
		point->field--;
	}
}

static	void	ft_put_precision_dprintf(t_pfspe *point, char *content)
{
	int i;

	i = 0;
	if (content != NULL)
	{
		while (point->precision > 0 && content[i])
		{
			ft_check_dbuffer(point, content[i]);
			point->precision--;
			i++;
		}
	}
}

void			ft_dprintfs(t_pfspe *point, char *content)
{
	char c;

	if (content == NULL)
	{
		ft_dprintfs(point, "(null)");
		return ;
	}
	if (point->point == 0 || point->precision > ft_strlen_longlong(content))
		point->field = point->field - ft_strlen_longlong(content);
	else
		point->field = point->field - point->precision;
	ft_flag_zero_dprintf(&c, point);
	if (point->minus > 0)
	{
		(point->point > 0) ? ft_put_precision_dprintf(point, content) :
							ft_copy_in_buffer(point, content);
		ft_put_dfield(point, c);
	}
	else
	{
		ft_put_dfield(point, c);
		(point->point > 0) ? ft_put_precision_dprintf(point, content) :
						ft_copy_in_buffer(point, content);
	}
}
