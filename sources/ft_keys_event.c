/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:27:42 by allallem          #+#    #+#             */
/*   Updated: 2019/08/31 15:22:02 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

uint32_t			ft_rotation_mouse(t_scop *env, SDL_Event e/*, const uint8_t *state*/)
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

uint32_t			ft_keys_event(t_scop *env, SDL_Event e, const uint8_t *state)
{
	ft_rotation_mouse(env, e);
	if (state[SDL_SCANCODE_ESCAPE] || e.window.event == SDL_WINDOWEVENT_CLOSE)
		env->event.run = 0;
	if (e.key.type == 5)
		env->event.run = 1;
	if (state[SDL_SCANCODE_RIGHT])
		env->trans.vecs[12] += env->trans.vecs[0];
	if (state[SDL_SCANCODE_W])
		env->trans.vecs[13] += env->trans.vecs[0];
	if (state[SDL_SCANCODE_S])
		env->trans.vecs[13] += -env->trans.vecs[0];
	if (state[SDL_SCANCODE_LEFT])
		env->trans.vecs[12] += -env->trans.vecs[0];
	if (state[SDL_SCANCODE_KP_PLUS])
	{
		env->trans.vecs[0] += 0.02;
		env->trans.vecs[5] += 0.02;
		env->trans.vecs[10] += 0.02;
	}
	if (state[SDL_SCANCODE_KP_MINUS])
	{
		env->trans.vecs[0] -= 0.02;
		env->trans.vecs[5] -= 0.02;
		env->trans.vecs[10] -= 0.02;
	}
	if (state[SDL_SCANCODE_X])
	{
		env->trans.anglex += 0.01;
		env->trans.rotatex[5] = cos(env->trans.anglex);
		env->trans.rotatex[6] = sin(env->trans.anglex);
		env->trans.rotatex[9] = -sin(env->trans.anglex);
		env->trans.rotatex[10] = cos(env->trans.anglex);
	}
	if (state[SDL_SCANCODE_Y])
	{
		env->trans.angley += 0.01;
		env->trans.rotatey[0] = cos(env->trans.angley);
		env->trans.rotatey[2] = -sin(env->trans.angley);
		env->trans.rotatey[8] = sin(env->trans.angley);
		env->trans.rotatey[10] = cos(env->trans.angley);
	}
	if (state[SDL_SCANCODE_Z])
	{
		env->trans.anglez += 0.01;
		env->trans.rotatez[0] = cos(env->trans.anglez);
		env->trans.rotatez[1] = sin(env->trans.anglez);
		env->trans.rotatez[4] = -sin(env->trans.anglez);
		env->trans.rotatez[5] = cos(env->trans.anglez);
	}
	return (1);
}
