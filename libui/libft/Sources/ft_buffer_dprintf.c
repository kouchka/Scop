/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_dprintf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 18:44:12 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:09:54 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pull_dall(t_pfspe *point)
{
	write(point->fd, point->contenu, point->cursor);
	point->value = point->value + point->cursor;
	point->cursor = 0;
}

void	ft_check_dbuffer(t_pfspe *point, char c)
{
	if (point->cursor == B_PF_SIZE)
	{
		write(point->fd, point->contenu, B_PF_SIZE);
		point->cursor = 0;
		point->value = point->value + (B_PF_SIZE);
	}
	point->contenu[point->cursor++] = c;
}
