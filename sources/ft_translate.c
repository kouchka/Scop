/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:08:42 by allallem          #+#    #+#             */
/*   Updated: 2019/07/09 15:42:11 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_translate(t_scop *env, float *vertices, float x, float y, float z)
{
	uint32_t i;

	i = 0;
	while (i + 9 < env->link_number * 9)
	{
		vertices[i] = vertices[i] * 1 + vertices[i + 1] * 0 + vertices[i + 2] * 0 + 1 * x;
		vertices[i + 1] = vertices[i] * 0 + vertices[i + 1] * 1 + vertices[i + 2] * 0 + 1 * y;
		vertices[i + 2] = vertices[i] * 0 + vertices[i + 1] * 0 + vertices[i + 2] * 1 + 1 * z;
		vertices[i + 3] = vertices[i + 3] * 1 + vertices[i + 4] * 0 + vertices[i + 5] * 0 + 1 * x;
		vertices[i + 4] = vertices[i + 3] * 0 + vertices[i + 4] * 1 + vertices[i + 5] * 0 + 1 * y;
		vertices[i + 5] = vertices[i + 3] * 0 + vertices[i + 4] * 0 + vertices[i + 5] * 1 + 1 * z;
		vertices[i + 6] = vertices[i + 6] * 1 + vertices[i + 7] * 0 + vertices[i + 8] * 0 + 1 * x;
		vertices[i + 7] = vertices[i + 6] * 0 + vertices[i + 7] * 1 + vertices[i + 8] * 0 + 1 * y;
		vertices[i + 8] = vertices[i + 6] * 0 + vertices[i + 7] * 0 + vertices[i + 8] * 1 + 1 * z;
		i += 9;
	}
	return (1);
}
