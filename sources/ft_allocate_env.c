/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:45:59 by allallem          #+#    #+#             */
/*   Updated: 2019/06/30 13:10:45 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int32_t		ft_free_allocated_triangle(t_scop *env, int32_t i)
{
	uint32_t j;

	j = 0;
	while (j < env->point_number)
	{
		free(env->point[j]);
		j++;
	}
	if (i > 0)
	{
		while (i >= 0)
		{
			free(env->triangle[i]);
			i--;
		}
	}
	free(env->point);
	free(env->triangle);
	return (0);
}

int32_t		ft_free_allocated(t_scop *env, int32_t i)
{
	if (i > 0)
	{
		while (i >= 0)
		{
			free(env->point[i]);
			i--;
		}
	}
	free(env->point);
	free(env->triangle);
	return (0);
}

int32_t		ft_allocate_env(t_scop *env)
{
	uint32_t	i;

	i = 0;
	if (!(env->point = ft_memalloc(sizeof(float *) * env->point_number))
			|| !(env->triangle = ft_memalloc(sizeof(uint32_t *)
				* env->link_number)))
		return (0);
	while (i < env->point_number)
	{
		if (!(env->point[i] = ft_memalloc(sizeof(float) * 3)))
			return (ft_free_allocated(env, i - 1));
		i++;
	}
	i = 0;
	while (i < env->link_number)
	{
		if (!(env->triangle[i] = ft_memalloc(sizeof(uint32_t) * 3)))
			return (ft_free_allocated_triangle(env, i - 1));
		i++;
	}
	return (1);
}
