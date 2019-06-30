/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:26:41 by allallem          #+#    #+#             */
/*   Updated: 2019/06/30 17:45:46 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char		*LoadSource(const char *filename)
{
	char *src = NULL;   /* code source de notre shader */
	FILE *fp = NULL;    /* fichier */
	long size;          /* taille du fichier */
	long i;             /* compteur */


	/* on ouvre le fichier */
	fp = fopen(filename, "r");
	/* on verifie si l'ouverture a echoue */
	if (fp == NULL)
	{
		ft_printf("impossible d'ouvrir le fichier '%s'\n", filename);
		return NULL;
	}
	/* on recupere la longueur du fichier */
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	/* on se replace au debut du fichier */
	rewind(fp);
	/* on alloue de la memoire pour y placer notre code source */
	src = malloc(size + 1); /* +1 pour le caractere de fin de chaine '\0' */
	if (src == NULL)
	{
		fclose(fp);
		ft_printf("erreur d'allocation de memoire!\n");
		return NULL;
	}
	/* lecture du fichier */
	for (i = 0; i < size; i++)
		src[i] = fgetc(fp);
	/* on place le dernier caractere a '\0' */
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

uint32_t			ft_run(t_scop *env)
{
	float					*vertices;
	SDL_Event			e;
	const uint8_t	*state;
	float					couleurs[] = {0.0, 204.0 / 255.0, 1.0, 0.0, 204.0 / 255.0,
		1.0, 0.0, 204.0/255.0, 1.0};
	GLuint shader;
	GLuint program;
	GLint logsize;
	GLint compile_status = GL_TRUE;
	char *str = LoadSource("Shaders/couleur2D.vert");

	/*
	** 	Creation shader
	*/
	if (!(shader = glCreateShader(GL_VERTEX_SHADER)))
		return (0);
	glShaderSource(shader, 1, (const GLchar**)&str, NULL);
	glCompileShader(shader);
	free(str);
	glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
	if (compile_status != GL_TRUE)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
		str = ft_memalloc(sizeof(char) * (logsize + 1));
		if (!str)
		{
			glDeleteShader(shader);
			return (0);
		}
		glGetShaderInfoLog(shader, logsize, &logsize, str);
		ft_printf("impossible de compiler le shadder :\n%s", str);
		free(str);
		glDeleteShader(shader);
		return (0);
	}

	/*
	**	Creation progamme + link
	*/
	program = glCreateProgram();
	glAttachShader(program, shader);
	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &compile_status);
	if (compile_status != GL_TRUE)
	{
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logsize);
		str = ft_memalloc(sizeof(char) * (logsize + 1));
		if (!str)
		{
			glDeleteProgram(program);
			glDeleteShader(shader);
			return (0);
		}
		glGetProgramInfoLog(shader, logsize, &logsize, str);
		ft_printf("impossible de compiler le shadder :\n%s", str);
		free(str);
		glDeleteProgram(program);
		glDeleteShader(shader);
		return (0);
	}

	if (!(vertices = ft_memalloc(sizeof(float) * (env->link_number * 9))))
	{
		glDeleteProgram(program);
		glDeleteShader(shader);
		ft_printf("Error while malloc vertices\n");
		return (0);
	}
	vertices[0] = 0.0;
	vertices[1] = 0.0;
	vertices[2] = -1.0;
	vertices[3] = 0.5;
	vertices[4] = 0.0;
	vertices[5] = -1.0;
	vertices[6] = 0.0;
	vertices[7] = 0.5;
	vertices[8] = -1.0;
	// ft_attribute_vertices(env, vertices);
	state = SDL_GetKeyboardState(NULL);
	while (env->event.run)
	{
		while (SDL_PollEvent(&e))
			ft_keys_event(env, e, state, vertices);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, couleurs);
		glEnableVertexAttribArray(1);
		glDrawArrays(GL_TRIANGLES, 0, env->link_number * 3);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);
		glUseProgram(0);
		SDL_GL_SwapWindow(env->sdl.win);
	}
	glDeleteProgram(program);
	glDeleteShader(shader);
	free(vertices);
	return (1);
}
