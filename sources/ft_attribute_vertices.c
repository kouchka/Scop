/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attribute_vertices.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:37:36 by allallem          #+#    #+#             */
/*   Updated: 2019/09/04 10:41:15 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		ft_attribute_vertices(t_scop *env, float *vertices)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	j = 0;
	while (j < env->link_number && ((i + 9) < (env->link_number * 9)))
	{
		vertices[i] = env->point[env->triangle[j][0] - 1][0];
		vertices[i + 1] = env->point[env->triangle[j][0] - 1][1];
		vertices[i + 2] = env->point[env->triangle[j][0] - 1][2];
		vertices[i + 3] = env->point[env->triangle[j][1] - 1][0];
		vertices[i + 4] = env->point[env->triangle[j][1] - 1][1];
		vertices[i + 5] = env->point[env->triangle[j][1] - 1][2];
		vertices[i + 6] = env->point[env->triangle[j][2] - 1][0];
		vertices[i + 7] = env->point[env->triangle[j][2] - 1][1];
		vertices[i + 8] = env->point[env->triangle[j][2] - 1][2];
		i += 9;
		j++;
	}
}

void		ft_rotate(t_scop *env)
{
	if (!env->event.rotate)
		return ;
	env->time.current_time = SDL_GetTicks();
	env->time.ellapsed_time = env->time.current_time - env->time.last_time;
	env->time.last_time = env->time.current_time;
	env->trans.angley += env->time.ellapsed_time * 0.001;
	env->trans.rotatey[0] = cos(env->trans.angley);
	env->trans.rotatey[2] = -sin(env->trans.angley);
	env->trans.rotatey[8] = sin(env->trans.angley);
	env->trans.rotatey[10] = cos(env->trans.angley);
}

void		ft_texture_interpolation(t_scop *env)
{
	if (env->event.texture == 1 && env->event.interpolate < 1.00)
		env->event.interpolate += 0.01;
	if (env->event.texture == 0 && env->event.interpolate > 0.00)
		env->event.interpolate -= 0.01;
	if (env->event.line)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (!env->event.line)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
