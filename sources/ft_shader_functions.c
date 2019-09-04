/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shader_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:00:54 by allallem          #+#    #+#             */
/*   Updated: 2019/09/04 10:57:11 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_check_create(char **str, char *file_name, GLuint *shader,
		GLuint options)
{
	if (!(*str = ft_loadsource(file_name)))
		return (0);
	if (!(*shader = glCreateShader(options)))
		return (0);
	return (1);
}

uint32_t			ft_create_shader(GLuint *shader, char *file_name,
		GLint compile_status, GLuint options)
{
	GLint	logsize;
	char	*str;

	if (!ft_check_create(&str, file_name, shader, options))
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

void				ft_create_prog(GLuint *program, GLuint *vertex,
	GLuint *frag)
{
	glAttachShader(*program, *frag);
	glAttachShader(*program, *vertex);
	glLinkProgram(*program);
}

void				ft_detach_prog(GLuint *program, GLuint *vertex,
	GLuint *frag)
{
	glDetachShader(*program, *vertex);
	glDetachShader(*program, *frag);
	glDeleteShader(*vertex);
	glDeleteShader(*frag);
}

uint32_t			ft_create_program(GLuint *program, GLuint *vertex,
	GLuint *frag, GLint compile_status)
{
	GLint	logsize;
	char	*str;

	*program = glCreateProgram();
	ft_create_prog(program, vertex, frag);
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
	ft_detach_prog(program, vertex, frag);
	return (1);
}
