/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:44:11 by allallem          #+#    #+#             */
/*   Updated: 2019/09/04 11:46:42 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint8_t				ft_fill_format(t_scop *env)
{
	if (env->texture->format->BytesPerPixel == 3)
	{
		env->formatinterne = GL_RGB;
		if (env->texture->format->Rmask == 0xff)
			env->format = GL_RGB;
		else
			env->format = GL_BGR;
	}
	else if (env->texture->format->BytesPerPixel == 4)
	{
		env->formatinterne = GL_RGBA;
		if (env->texture->format->Rmask == 0xff)
			env->format = GL_RGBA8;
		else
			env->format = GL_BGRA;
	}
	else
	{
		ft_printf("Erreur, format interne de l'image inconnu\n");
		SDL_FreeSurface(env->texture);
		return (0);
	}
	return (1);
}

uint8_t				ft_init_texture(t_scop *env)
{
	if (!(env->texture = IMG_Load("cat.jpg")))
	{
		ft_printf("%s\n", SDL_GetError());
		return (0);
	}
	glGenTextures(1, &env->texture_id);
	glBindTexture(GL_TEXTURE_2D, env->texture_id);
	return (ft_fill_format(env));
}

uint32_t			ft_load_texture(t_scop *env)
{
	if (!ft_init_texture(env))
		return (0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, env->formatinterne, env->texture->w,
		env->texture->h, 0, env->format, GL_UNSIGNED_BYTE,
		env->texture->pixels);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(env->texture);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	ft_bind_color(env, 0, 0);
	ft_bind_texture_coord(env);
	return (1);
}
