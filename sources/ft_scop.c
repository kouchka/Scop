/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:30:31 by allallem          #+#    #+#             */
/*   Updated: 2019/06/30 18:07:38 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_init_glew(t_scop *env)
{
	if (glewInit() != GLEW_OK)
	{
		ft_printf("Error while glewInit : %s", glewGetErrorString(glewInit()));
		ft_quit_sdl(&env->sdl.win, &env->sdl.ren, 0);
		return (0);
	}
	return (1);
}

uint32_t			ft_init_window(t_scop *env, char *name)
{
	env->sdl.name = ft_strjoin("scop : ", name);
	if (!env->sdl.name)
		return (ERROR);
	env->sdl.winpos_x = 50;
	env->sdl.winpos_y = 50;
	env->sdl.width = 1920;
	env->sdl.height = 1080;
	return (SUCCESS);
}

uint32_t			ft_scop(t_scop *env, char *name)
{
	if (!ft_init_window(env, name) || !ft_init_sdl(SDL_INIT_VIDEO))
		return (0);
	if (!ft_sdl_create_window(&env->sdl, SDL_WINDOW_OPENGL))
	{
		ft_quit_sdl(&env->sdl.win, &env->sdl.ren, 0);
		return (0);
	}
	free(env->sdl.name);
	if (!(env->sdl.cont = SDL_GL_CreateContext(env->sdl.win)))
	{
		ft_printf("Error while creating context : %s\n", SDL_GetError());
		return (0);
	}
	if (!ft_init_glew(env))
		return (0);
	// glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	env->event.run = 1;
	ft_run(env);
	return (1);
}
