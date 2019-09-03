/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_opengl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:22:58 by allallem          #+#    #+#             */
/*   Updated: 2019/09/03 13:17:04 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					ft_update_rotate(t_scop *env, GLuint program)
{
	GLint	id;
	float	rotatetmp[16];

	ft_mat4_multiplication(env->trans.rotate, env->trans.rotatex, env->trans.rotatey);
	memcpy(&rotatetmp, &env->trans.rotate, sizeof(float) * 16);
	ft_mat4_multiplication(env->trans.rotate, rotatetmp, env->trans.rotatez);
	memcpy(&rotatetmp, &env->trans.rotate, sizeof(float) * 16);
	ft_mat4_multiplication(env->trans.rotate, rotatetmp, env->trans.vecs);
	id = glGetUniformLocation(program, "projection");
	glUniformMatrix4fv(id, 1, GL_FALSE, env->trans.rotate);
}

void					ft_update_data(t_scop *env, GLuint program)
{
	uint32_t interpolate;

	interpolate = glGetUniformLocation(program, "interpolate");
	glUniform1f(interpolate, env->event.interpolate);
	ft_update_rotate(env, program);
}
