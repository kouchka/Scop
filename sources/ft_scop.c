/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 13:30:31 by allallem          #+#    #+#             */
/*   Updated: 2019/09/03 13:34:55 by allallem         ###   ########.fr       */
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

void				ft_identity_init(float *mat, float value)
{
	mat[0] = value;
	mat[5] = value;
	mat[10] = value;
	mat[15] = value;
}

void				ft_assign_vecs(t_scop *env)
{
	ft_identity_init(env->trans.vecs, 1.0);
	ft_identity_init(env->trans.rotatex, 1.0);
	ft_identity_init(env->trans.rotatey, 1.0);
	ft_identity_init(env->trans.rotatez, 1.0);
	ft_identity_init(env->trans.rotate, 1.0);
	env->trans.vecs[0] -= 0.7;
	env->trans.vecs[5] -= 0.7;
	env->trans.vecs[10] -= 0.7;
}

uint32_t			ft_scop(t_scop *env, char *name)
{
	ft_assign_vecs(env);
	if (!ft_init_window(env, name) || !ft_init_sdl(SDL_INIT_VIDEO))
		return (0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
		SDL_GL_CONTEXT_PROFILE_CORE);
	if (!ft_sdl_create_window(&env->sdl, SDL_WINDOW_OPENGL))
	{
		ft_quit_sdl(&env->sdl.win, &env->sdl.ren, 0);
		return (0);
	}
	env->event.rotate = 1;
	free(env->sdl.name);
	if (!(env->sdl.cont = SDL_GL_CreateContext(env->sdl.win)))
	{
		ft_printf("Error while creating context : %s\n", SDL_GetError());
		return (0);
	}
	if (!ft_init_glew(env))
		return (0);
	env->event.run = 1;
	ft_center(env);
	ft_run(env);
	return (1);
}
