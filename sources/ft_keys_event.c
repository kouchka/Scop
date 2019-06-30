/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 14:27:42 by allallem          #+#    #+#             */
/*   Updated: 2019/06/30 15:06:44 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"



uint32_t			ft_keys_event(t_scop *env, SDL_Event e, const uint8_t *state
				, float *vertices)
{
	if (state[SDL_SCANCODE_ESCAPE] || e.window.event == SDL_WINDOWEVENT_CLOSE)
		env->event.run = 0;
	if (e.key.type == 5)
		env->event.run = 1;
	if (state[SDL_SCANCODE_RIGHT])
		return (ft_translate(env, vertices, 0.2, 0, 0));
	if (state[SDL_SCANCODE_LEFT])
		return (ft_translate(env, vertices, -0.2, 0, 0));
	if (state[SDL_SCANCODE_UP])
		return (ft_translate(env, vertices, 0, 0.2, 0));
	if (state[SDL_SCANCODE_DOWN])
		return (ft_translate(env, vertices, 0, -0.2, 0));
	if (state[SDL_SCANCODE_P])
		return (ft_homothetie(env, vertices, 1.2, 1.2, 1.2));
	if (state[SDL_SCANCODE_M])
		return (ft_homothetie(env, vertices, 0.8, 0.8, 0.8));
	if (state[SDL_SCANCODE_O])
		return (ft_rotate(env, vertices, 0.0, 0.0, 0.1));
	return (1);
}
