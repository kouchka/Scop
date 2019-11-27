/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mat4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:33:44 by allallem          #+#    #+#             */
/*   Updated: 2019/09/17 14:46:22 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_mat		*mat_new(int width, int height)
{
	t_mat *to_return;

	to_return = (t_mat*)malloc(sizeof(t_mat));
	to_return->array = malloc(width * height * sizeof(float));
	to_return->width = width;
	to_return->height = height;
	return (to_return);
}

void		mat_zero(t_mat *dest)
{
	bzero(dest->array, dest->width * dest->height * sizeof(float));
}

void		mat_set(t_mat *m, int x, int y, float val)
{
	if (m == NULL || x > m->width || y > m->height)
		return ;
	m->array[m->width * (y - 1) + (x - 1)] = val;
}

t_mat		*ft_mat_perspective(float angle, float ratio,
			float near, float far)
{
	t_mat	*to_return;
	float	tan_half_angle;

	to_return = mat_new(4, 4);
	mat_zero(to_return);
	tan_half_angle = tan(angle / 2);
	mat_set(to_return, 1, 1, 1 / (ratio * tan_half_angle));
	mat_set(to_return, 2, 2, 1 / (tan_half_angle));
	mat_set(to_return, 3, 3, -(far + near) / (far - near));
	mat_set(to_return, 4, 3, -1);
	mat_set(to_return, 3, 4, -(2 * far * near) / (far - near));
	return (to_return);
}
