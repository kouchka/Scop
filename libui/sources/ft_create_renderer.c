/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_renderer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:51:58 by allallem          #+#    #+#             */
/*   Updated: 2019/05/27 11:48:00 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int32_t		ft_sdl_create_renderer(t_window *win, uint32_t flags)
{
	if ((win->ren = SDL_CreateRenderer(win->win, -1, flags)) == NULL)
	{
		ft_printf("SDL_CreateRenderer Error: %s %s\n", SDL_GetError());
		return (ERROR);
	}
	return (SUCCESS);
}
