/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:41:47 by allallem          #+#    #+#             */
/*   Updated: 2019/05/29 13:56:02 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_update_window(t_window *win, SDL_Surface *image)
{
	SDL_Texture *convert;

	convert = SDL_CreateTextureFromSurface(win->ren, image);
	SDL_RenderCopy(win->ren, convert, NULL, NULL);
	SDL_RenderPresent(win->ren);
	SDL_DestroyTexture(convert);
}
