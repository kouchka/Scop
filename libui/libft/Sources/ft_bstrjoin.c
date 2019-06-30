/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlehideu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:30:49 by jlehideu          #+#    #+#             */
/*   Updated: 2019/03/18 14:30:51 by jlehideu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_bstrjoin(char *s1, char *s2)
{
	char	*result;
	int		idx_r;
	int		idx_d;

	result = 0;
	if (!s1 || !s2)
		return (0);
	idx_d = ft_strlen(s1) + ft_strlen(s2);
	if (!(result = (char*)malloc(sizeof(char) * idx_d + 2)))
		return (0);
	if (!s1)
		return (0);
	idx_r = -1;
	idx_d = -1;
	while (s1[++idx_d])
		result[++idx_r] = s1[idx_d];
	idx_d = -1;
	while (s2[++idx_d])
		result[++idx_r] = s2[idx_d];
	result[++idx_r] = '\0';
	free(s1);
	free(s2);
	return (result);
}
