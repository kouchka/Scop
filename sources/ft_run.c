/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:26:41 by allallem          #+#    #+#             */
/*   Updated: 2019/09/04 12:08:38 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				ft_bind_vertices(t_scop *env)
{
	ft_attribute_vertices(env, env->vertices);
	glGenVertexArrays(1, &env->vao);
	glGenBuffers(1, &env->vbo);
	glBindVertexArray(env->vao);
	glBindBuffer(GL_ARRAY_BUFFER, env->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (env->link_number * 9),
		env->vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

uint8_t				ft_shader_vertices(t_scop *env)
{
	if (!ft_create_shader(&env->vertex, "Shaders/translate.vert", GL_TRUE,
		GL_VERTEX_SHADER))
		return (0);
	if (!ft_create_shader(&env->frag, "Shaders/basique2D.frag", GL_TRUE,
		GL_FRAGMENT_SHADER))
		return (0);
	if (!ft_create_program(&env->program, &env->vertex, &env->frag, GL_TRUE))
		return (0);
	if (!(env->vertices = ft_memalloc(sizeof(float) * (env->link_number * 9))))
	{
		glDeleteProgram(env->program);
		ft_printf("Error while malloc vertices\n");
		return (0);
	}
	ft_bind_vertices(env);
	if (!ft_load_texture(env))
		return (0);
	return (1);
}

uint32_t			ft_run(t_scop *env)
{
	SDL_Event		e;
	const uint8_t	*state;

	state = SDL_GetKeyboardState(NULL);
	if (!ft_shader_vertices(env))
		return (0);
	while (env->event.run)
	{
		ft_texture_interpolation(env);
		while (SDL_PollEvent(&e))
			ft_keys_event(env, e, state);
		glClearColor(1.0f, 1.00f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(env->program);
		glBindTexture(GL_TEXTURE_2D, env->texture_id);
		ft_rotate(env);
		ft_update_data(env, env->program);
		glBindVertexArray(env->vao);
		glDrawArrays(GL_TRIANGLES, 0, env->link_number * 3);
		SDL_GL_SwapWindow(env->sdl.win);
		SDL_GetMouseState(&env->event.x, &env->event.y);
	}
	glDeleteProgram(env->program);
	free(env->vertices);
	return (1);
}
