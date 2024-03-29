/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_opengl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:22:58 by allallem          #+#    #+#             */
/*   Updated: 2019/09/17 14:34:53 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					ft_update_data(t_scop *env, GLuint program)
{
	uint32_t	interpolate;
	GLint		id;
	float		tmp[16];

	interpolate = glGetUniformLocation(program, "interpolate");
	glUniform1f(interpolate, env->event.interpolate);
	ft_mat4_multiplication(env->trans.rotate, env->trans.rotatex,
		env->trans.rotatey);
	memcpy(&tmp, &env->trans.rotate, sizeof(float) * 16);
	ft_mat4_multiplication(env->trans.rotate, tmp, env->trans.rotatez);
	memcpy(&tmp, &env->trans.rotate, sizeof(float) * 16);
	ft_mat4_multiplication(env->trans.rotate, tmp, env->trans.vecs);
	memcpy(&tmp, &env->trans.rotate, sizeof(float) * 16);
	ft_mat4_multiplication(env->trans.rotate, tmp, env->projection->array);
	id = glGetUniformLocation(program, "mvp");
	glUniformMatrix4fv(id, 1, GL_FALSE, env->trans.rotate);
}
