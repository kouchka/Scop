/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_opengl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:22:58 by allallem          #+#    #+#             */
/*   Updated: 2019/09/01 16:01:40 by allallem         ###   ########.fr       */
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
	uint32_t vertexcolorlocation;
	float timevalue;
	float greenvalue;

	vertexcolorlocation= glGetUniformLocation(program, "vertex_color");
	timevalue = (float)(SDL_GetTicks() / 1000);
	greenvalue = (sin(timevalue) / 2.0f) + 0.5f;
	glUniform4f(vertexcolorlocation, 0.0f, 0.2f/*greenvalue*/, 0.0f, 1.0f);
	ft_update_rotate(env, program);
}
