/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_average.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:44:52 by allallem          #+#    #+#             */
/*   Updated: 2019/09/02 16:44:57 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					ft_average(t_scop *env, int position)
{
	long double average;
	uint32_t index;

	index = 0;
	average = 0;
	while (index < env->point_number)
	{
		average += env->point[index][position];
		index++;
	}
	average = average / env->point_number;
	index = 0;
	while (index < env->point_number)
	{
		env->point[index][position] -= average;
		index++;
	}
}

void					ft_center(t_scop *env)
{
	ft_average(env, 0);
	ft_average(env, 1);
	ft_average(env, 2);
}
