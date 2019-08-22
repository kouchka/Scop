/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:41:14 by allallem          #+#    #+#             */
/*   Updated: 2019/08/22 16:18:35 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			ft_check_mat4(float *mat4)
{
	printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n", mat4[0],
		mat4[1], mat4[2], mat4[3], mat4[4], mat4[5], mat4[6], mat4[7], mat4[8],
		mat4[9], mat4[10], mat4[11], mat4[12], mat4[13], mat4[14], mat4[15]);
}

void			ft_print_table(t_scop *env)
{
	uint32_t i;

	i = 0;
	while (i < env->point_number)
	{
		printf("point %i : %f %f %f\n", i, env->point[i][0], env->point[i][1], env->point[i][2]);
		i++;
	}
	i = 0;
	while (i < env->link_number)
	{
		printf("surface %i : %u %u %u\n", i, env->triangle[i][0], env->triangle[i][1], env->triangle[i][2]);
		i++;
	}
}
