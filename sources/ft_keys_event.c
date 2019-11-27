/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:27:42 by allallem          #+#    #+#             */
/*   Updated: 2019/09/17 14:30:16 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_rotation_mouse(t_scop *env, SDL_Event e)
{
	int32_t x;
	int32_t y;

	if (e.button.button == SDL_BUTTON_LEFT)
	{
		SDL_GetMouseState(&x, &y);
		env->trans.anglex += (env->event.y - y) * -0.001;
		env->trans.rotatex[5] = cos(env->trans.anglex);
		env->trans.rotatex[6] = sin(env->trans.anglex);
		env->trans.rotatex[9] = -sin(env->trans.anglex);
		env->trans.rotatex[10] = cos(env->trans.anglex);
		env->trans.angley += (env->event.x - x) * -0.001;
		env->trans.rotatey[0] = cos(env->trans.angley);
		env->trans.rotatey[2] = -sin(env->trans.angley);
		env->trans.rotatey[8] = sin(env->trans.angley);
		env->trans.rotatey[10] = cos(env->trans.angley);
	}
	return (1);
}

uint32_t			ft_homotethie(t_scop *env, SDL_Event e)
{
	if (e.wheel.y < 0)
		env->trans.vecs[14] -= 0.1;
	if (e.wheel.y > 0)
		env->trans.vecs[14] += 0.1;
	return (1);
}

uint32_t			ft_rotate_keys(t_scop *env, const uint8_t *s)
{
	if (s[SDL_SCANCODE_X])
	{
		env->trans.anglex += 0.01;
		env->trans.rotatex[5] = cos(env->trans.anglex);
		env->trans.rotatex[6] = sin(env->trans.anglex);
		env->trans.rotatex[9] = -sin(env->trans.anglex);
		env->trans.rotatex[10] = cos(env->trans.anglex);
	}
	if (s[SDL_SCANCODE_Y])
	{
		env->trans.angley += 0.01;
		env->trans.rotatey[0] = cos(env->trans.angley);
		env->trans.rotatey[2] = -sin(env->trans.angley);
		env->trans.rotatey[8] = sin(env->trans.angley);
		env->trans.rotatey[10] = cos(env->trans.angley);
	}
	if (s[SDL_SCANCODE_Z])
	{
		env->trans.anglez += 0.01;
		env->trans.rotatez[0] = cos(env->trans.anglez);
		env->trans.rotatez[1] = sin(env->trans.anglez);
		env->trans.rotatez[4] = -sin(env->trans.anglez);
		env->trans.rotatez[5] = cos(env->trans.anglez);
	}
	return (1);
}

uint32_t			ft_texture(t_scop *env)
{
	if (env->event.texture == 1)
		env->event.texture = 0;
	else
		env->event.texture = 1;
	return (1);
}

uint32_t			ft_keys_event(t_scop *env, SDL_Event e, const uint8_t *s)
{
	ft_rotation_mouse(env, e);
	if (s[SDL_SCANCODE_ESCAPE] || e.window.event == SDL_WINDOWEVENT_CLOSE)
		env->event.run = 0;
	if (e.key.type == 5)
		env->event.run = 1;
	if (s[SDL_SCANCODE_RIGHT])
		env->trans.vecs[12] += env->trans.vecs[0];
	if (s[SDL_SCANCODE_W])
		env->trans.vecs[13] += env->trans.vecs[0];
	if (s[SDL_SCANCODE_S])
		env->trans.vecs[13] += -env->trans.vecs[0];
	if (s[SDL_SCANCODE_LEFT])
		env->trans.vecs[12] += -env->trans.vecs[0];
	if (e.type == SDL_MOUSEWHEEL)
		return (ft_homotethie(env, e));
	if (s[SDL_SCANCODE_X] || s[SDL_SCANCODE_Y] || s[SDL_SCANCODE_Z])
		return (ft_rotate_keys(env, s));
	if (s[SDL_SCANCODE_T] && e.key.type == SDL_KEYDOWN && !e.key.repeat)
		return (ft_texture(env));
	if (s[SDL_SCANCODE_L] && e.key.type == SDL_KEYDOWN && !e.key.repeat
		&& !env->event.line)
		env->event.line = 1;
	else if (s[SDL_SCANCODE_L] && e.key.type == SDL_KEYDOWN && !e.key.repeat)
		env->event.line = 0;
	return (1);
}
