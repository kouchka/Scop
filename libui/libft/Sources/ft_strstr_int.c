/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:54:10 by allallem          #+#    #+#             */
/*   Updated: 2019/01/17 17:08:33 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr_int(char const *dest, char const pattern)
{
	size_t i;

	i = 0;
	if (!pattern || !dest)
		return (-1);
	while (dest[i] != pattern && dest[i])
		i++;
	if (pattern == dest[i])
		return (1);
	return (0);
}
