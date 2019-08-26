/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:26:41 by allallem          #+#    #+#             */
/*   Updated: 2019/08/26 14:13:29 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char		*LoadSource(const char *filename)
{
	char *src = NULL;
	FILE *fp = NULL;
	long size;
	long i;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		ft_printf("impossible d'ouvrir le fichier '%s'\n", filename);
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	src = malloc(size + 1);
	if (src == NULL)
	{
		fclose(fp);
		ft_printf("erreur d'allocation de memoire!\n");
		return NULL;
	}
	for (i = 0; i < size; i++)
		src[i] = fgetc(fp);
	src[size] = '\0';
	fclose(fp);
	return src;
}

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

uint32_t			ft_create_shader(GLuint *shader, char *file_name,
		GLint compile_status, GLuint options)
{
	GLint logsize;
	char *str;

	if (!(str = LoadSource(file_name)))
		return 0;
	if (!(*shader = glCreateShader(options)))
		return (0);
	glShaderSource(*shader, 1, (const GLchar**)&str, NULL);
	glCompileShader(*shader);
	free(str);
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &compile_status);
	if (compile_status != GL_TRUE)
	{
		glGetShaderiv(*shader, GL_INFO_LOG_LENGTH, &logsize);
		str = ft_memalloc(sizeof(char) * (logsize + 1));
		if (!str)
		{
			glDeleteShader(*shader);
			return (0);
		}
		glGetShaderInfoLog(*shader, logsize, &logsize, str);
		ft_printf("impossible de compiler le shadder :\n%s", str);
		free(str);
		glDeleteShader(*shader);
		return (0);
	}
	return (1);
}

uint32_t			ft_create_program(GLuint *program, GLuint *vertex, GLuint *frag,
	GLint compile_status)
{
	GLint logsize;
	char *str;

	*program = glCreateProgram();
	glAttachShader(*program, *frag);
	glAttachShader(*program, *vertex);
	glLinkProgram(*program);
	glGetProgramiv(*program, GL_LINK_STATUS, &compile_status);
	if (compile_status != GL_TRUE)
	{
		glGetProgramiv(*program, GL_INFO_LOG_LENGTH, &logsize);
		str = ft_memalloc(sizeof(char) * (logsize + 1));
		if (!str)
		{
			glDeleteProgram(*program);
			glDeleteShader(*vertex);
			return (0);
		}
		glGetProgramInfoLog(*program, logsize, &logsize, str);
		printf("impossible de créer le programme :\n%s", str);
		free(str);
		glDeleteProgram(*program);
		glDeleteShader(*vertex);
		return (0);
	}
	glDetachShader(*program, *vertex);
	glDetachShader(*program, *frag);
	glDeleteShader(*vertex);
	glDeleteShader(*frag);
	return (1);
}

void					ft_mat4_multiplication(float *m, float *m1, float *m2)
{
	m[0] = (m1[0] * m2[0]) + (m1[1] * m2[4]) + (m1[2] * m2[8]) + (m1[3] * m2[12]);
	m[1] = (m1[0] * m2[1]) + (m1[1] * m2[5]) + (m1[2] * m2[9]) + (m1[3] * m2[13]);
	m[2] = (m1[0] * m2[2]) + (m1[1] * m2[6]) + (m1[2] * m2[10]) + (m1[3] * m2[14]);
	m[3] = (m1[0] * m2[3]) + (m1[1] * m2[7]) + (m1[2] * m2[11]) + (m1[3] * m2[15]);
	m[4] = (m1[4] * m2[0]) + (m1[5] * m2[4]) + (m1[6] * m2[8]) + (m1[7] * m2[12]);
	m[5] = (m1[4] * m2[1]) + (m1[5] * m2[5]) + (m1[6] * m2[9]) + (m1[7] * m2[13]);
	m[6] = (m1[4] * m2[2]) + (m1[5] * m2[6]) + (m1[6] * m2[10]) + (m1[7] * m2[14]);
	m[7] = (m1[4] * m2[3]) + (m1[5] * m2[7]) + (m1[6] * m2[11]) + (m1[7] * m2[15]);
	m[8] = (m1[8] * m2[0]) + (m1[9] * m2[4]) + (m1[10] * m2[8]) + (m1[11] * m2[12]);
	m[9] = (m1[8] * m2[1]) + (m1[9] * m2[5]) + (m1[10] * m2[9]) + (m1[11] * m2[13]);
	m[10] = (m1[8] * m2[2]) + (m1[9] * m2[6]) + (m1[10] * m2[10]) + (m1[11] * m2[14]);
	m[11] = (m1[8] * m2[3]) + (m1[9] * m2[7]) + (m1[10] * m2[11]) + (m1[11] * m2[15]);
	m[12] = (m1[12] * m2[0]) + (m1[13] * m2[4]) + (m1[14] * m2[8]) + (m1[15] * m2[12]);
	m[13] = (m1[12] * m2[1]) + (m1[13] * m2[5]) + (m1[14] * m2[9]) + (m1[15] * m2[13]);
	m[14] = (m1[12] * m2[2]) + (m1[13] * m2[6]) + (m1[14] * m2[10]) + (m1[15] * m2[14]);
	m[15] = (m1[12] * m2[3]) + (m1[13] * m2[7]) + (m1[14] * m2[11]) + (m1[15] * m2[15]);
}

void					ft_update_rotate(t_scop *env, GLuint program)
{
	GLint	id;
	float	rotatetmp[16];

	ft_mat4_multiplication(env->trans.rotate, env->trans.rotatex, env->trans.rotatey);
	memcpy(&rotatetmp, &env->trans.rotate, sizeof(float) * 16);
	ft_mat4_multiplication(env->trans.rotate, rotatetmp, env->trans.rotatez);
	id = glGetUniformLocation(program, "rotate");
	glUniformMatrix4fv(id, 1, GL_FALSE, env->trans.rotate);
}

void					ft_update_data(t_scop *env, GLuint program)
{
	uint32_t vertexColorLocation;
	float timeValue;
	float greenValue;
	GLint id;

	id = glGetUniformLocation(program, "trans");
	vertexColorLocation= glGetUniformLocation(program, "vertex_color");
	timeValue = SDL_GetTicks() / 120;
	greenValue = (sin(timeValue) / 2.0f) + 0.5f;
	glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
	glUniformMatrix4fv(id, 1, GL_FALSE, env->trans.vecs);
	ft_update_rotate(env, program);
}

uint32_t			ft_run(t_scop *env)
{
	float					*vertices;
	SDL_Event			e;
	const uint8_t	*state;
	GLuint vertex;
	GLuint frag;
	GLuint program;

	/*
	** 	Creation vertex
	*/
	if (!ft_create_shader(&vertex, "Shaders/translate.vert", GL_TRUE,
		GL_VERTEX_SHADER))
		return (0);
	if (!ft_create_shader(&frag, "Shaders/basique2D.frag", GL_TRUE,
		GL_FRAGMENT_SHADER))
		return (0);
	/*
	**	Creation progamme + link
	*/
	if (!ft_create_program(&program, &vertex, &frag, GL_TRUE))
		return (0);

	if (!(vertices = ft_memalloc(sizeof(float) * (env->link_number * 9))))
	{
		glDeleteProgram(program);
		ft_printf("Error while malloc vertices\n");
		return (0);
	}
	// vertices[0] = -0.5f;
	// vertices[1] = -0.5f;
	// vertices[2] = 0.0f;
	// vertices[3] = 0.5f;
	// vertices[4] = -0.5f;
	// vertices[5] = 0.0f;
	// vertices[6] = 0.0f;
	// vertices[7] = 0.5f;
	// vertices[8] = 0.0f;
	ft_attribute_vertices(env, vertices);

	GLuint VBO, VAO;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (env->link_number * 9),
		vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0,
			0);
	glEnableVertexAttribArray(0);
	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
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
