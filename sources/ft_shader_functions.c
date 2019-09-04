/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shader_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:00:54 by allallem          #+#    #+#             */
/*   Updated: 2019/09/03 13:38:33 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_create_shader(GLuint *shader, char *file_name,
		GLint compile_status, GLuint options)
{
	GLint logsize;
	char *str;

	if (!(str = ft_loadsource(file_name)))
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
