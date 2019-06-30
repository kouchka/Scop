/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_homothetie.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:25:01 by allallem          #+#    #+#             */
/*   Updated: 2019/06/30 13:14:22 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_homothetie(t_scop *env, float *vertices, float x, float y, float z)
{
	uint32_t i;

	i = 0;
	while (i + 9 < env->link_number * 9)
	{
		vertices[i] = vertices[i] * x + vertices[i + 1] * 0 + vertices[i + 2] * 0 + 1 * 0;
		vertices[i + 1] = vertices[i] * 0 + vertices[i + 1] * y + vertices[i + 2] * 0 + 1 * 0;
		vertices[i + 2] = vertices[i] * 0 + vertices[i + 1] * 0 + vertices[i + 2] * z + 1 * 0;
		vertices[i + 3] = vertices[i + 3] * x + vertices[i + 4] * 0 + vertices[i + 5] * 0 + 1 * 0;
		vertices[i + 4] = vertices[i + 3] * 0 + vertices[i + 4] * y + vertices[i + 5] * 0 + 1 * 0;
		vertices[i + 5] = vertices[i + 3] * 0 + vertices[i + 4] * 0 + vertices[i + 5] * z + 1 * 0;
		vertices[i + 6] = vertices[i + 6] * x + vertices[i + 7] * 0 + vertices[i + 8] * 0 + 1 * 0;
		vertices[i + 7] = vertices[i + 6] * 0 + vertices[i + 7] * y + vertices[i + 8] * 0 + 1 * 0;
		vertices[i + 8] = vertices[i + 6] * 0 + vertices[i + 7] * 0 + vertices[i + 8] * z + 1 * 0;
		i += 9;
	}
	return (1);
}
