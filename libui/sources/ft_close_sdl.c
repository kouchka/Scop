/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_sdl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:50:39 by allallem          #+#    #+#             */
/*   Updated: 2019/05/24 15:20:48 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void			ft_quit_ttf(void)
{
	TTF_Quit();	
}

int32_t		ft_quit_sdl(SDL_Window **win, SDL_Renderer **ren, SDL_Surface **image)
{
	if (*ren)
		SDL_DestroyRenderer(*ren);
	if (*win)
		SDL_DestroyWindow(*win);
	if (*image)
		SDL_FreeSurface(*image);
	SDL_Quit();
	return (1);
}
