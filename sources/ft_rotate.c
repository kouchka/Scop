/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:37:34 by allallem          #+#    #+#             */
/*   Updated: 2019/06/30 14:05:24 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "scop.h"

uint32_t				ft_rotate(t_scop *env, float *vertices, float x, float y, float z)
{
	uint32_t i;
	float		constant;

	constant = 1 - cos(TETA);
	i = 0;
	while (i + 3 < env->link_number * 9)
	{
		vertices[i] = vertices[i] * (x * x * constant + cos(TETA))
								+ vertices[i + 1] * (x * y * constant - (z * sin(TETA)))
								+ vertices[i + 2] * (x * z * constant + (y * sin(TETA)));
		vertices[i + 1] = vertices[i] * (x * y * constant + (z * sin(TETA)))
								+ vertices[i + 1] * (y * y * constant + cos(TETA))
								+ vertices[i + 2] * (z * y * constant - (x * sin(TETA)));
		vertices[i + 2] = vertices[i] * (x * z * constant - (y * sin(TETA)))
								+ vertices[i + 1] * (y * z * constant + (x * sin(TETA)))
								+ vertices[i + 2] * (z * z * constant + cos(TETA));
		i += 3;
	}
	return (1);
}
