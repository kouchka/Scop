/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:43:39 by allallem          #+#    #+#             */
/*   Updated: 2019/09/04 11:57:02 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

uint32_t	ft_get_color_sdl2(SDL_Surface *image, int32_t x, int32_t y)
{
	uint32_t	color;
	uint32_t	*convert;
	int32_t		position;

	if (x < 0 || y < 0
		|| (position = y * image->w + x) >= (image->w * image->h))
		return (0);
	convert = (uint32_t *)image->pixels;
	color = convert[position];
	return (color);
}
