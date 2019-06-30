/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:41:14 by allallem          #+#    #+#             */
/*   Updated: 2019/06/10 15:46:34 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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
