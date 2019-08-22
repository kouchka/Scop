/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:27:42 by allallem          #+#    #+#             */
/*   Updated: 2019/08/22 16:43:11 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"



uint32_t			ft_keys_event(t_scop *env, SDL_Event e, const uint8_t *state)
{
	if (state[SDL_SCANCODE_ESCAPE] || e.window.event == SDL_WINDOWEVENT_CLOSE)
		env->event.run = 0;
	if (e.key.type == 5)
		env->event.run = 1;
	if (state[SDL_SCANCODE_RIGHT])
		env->vecs[12] += 1.0;
	if (state[SDL_SCANCODE_UP])
		env->vecs[13] += 1.0;
	if (state[SDL_SCANCODE_DOWN])
		env->vecs[13] += -1.0;
	if (state[SDL_SCANCODE_LEFT])
		env->vecs[12] += -1.0;
	if (state[SDL_SCANCODE_KP_PLUS])
	{
		env->vecs[0] += 0.1;
		env->vecs[5] += 0.1;
		env->vecs[10] += 0.1;
	}
	if (state[SDL_SCANCODE_KP_MINUS])
	{
		env->vecs[0] -= 0.1;
		env->vecs[5] -= 0.1;
		env->vecs[10] -= 0.1;
	}
	return (1);
}
