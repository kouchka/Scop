/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 09:22:02 by allallem          #+#    #+#             */
/*   Updated: 2019/06/19 14:13:43 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
**using 2 pointer in SDL to close the actual window and renderer
**then quit SDL
*/

int		ft_init_sdl_2(SDL_Window **win, SDL_Renderer **ren, SDL_Surface **image)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		ft_printf("Unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();
		return (ERROR);
	}
	if (ft_sdl_create_window(win) || ft_sdl_create_renderer(ren, win)
			|| ft_sdl_create_surface(image))
		return (ft_quit_sdl(win, ren, image));
}
