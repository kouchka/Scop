/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:26:41 by allallem          #+#    #+#             */
/*   Updated: 2019/08/26 15:10:21 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					ft_attribute_vertices(t_scop *env, float *vertices)
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

uint32_t			ft_run(t_scop *env)
{
	float					*vertices;
	SDL_Event			e;
	const uint8_t	*state;
	GLuint vertex;
	GLuint frag;
	GLuint program;
	GLuint VBO, VAO;

	if (!ft_create_shader(&vertex, "Shaders/translate.vert", GL_TRUE,
		GL_VERTEX_SHADER))
		return (0);
	if (!ft_create_shader(&frag, "Shaders/basique2D.frag", GL_TRUE,
		GL_FRAGMENT_SHADER))
		return (0);
	if (!ft_create_program(&program, &vertex, &frag, GL_TRUE))
		return (0);
	if (!(vertices = ft_memalloc(sizeof(float) * (env->link_number * 9))))
	{
		glDeleteProgram(program);
		ft_printf("Error while malloc vertices\n");
		return (0);
	}
	ft_attribute_vertices(env, vertices);
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (env->link_number * 9),
		vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,
			0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	state = SDL_GetKeyboardState(NULL);
	while (env->event.run)
	{
		while (SDL_PollEvent(&e))
			ft_keys_event(env, e, state);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(program);
		ft_update_data(env, program);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, env->link_number * 3);
		SDL_GL_SwapWindow(env->sdl.win);
	}
	glDeleteProgram(program);
	free(vertices);
	return (1);
}
