/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_surface.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:07:56 by allallem          #+#    #+#             */
/*   Updated: 2019/05/24 15:08:30 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_sdl_create_surface(SDL_Surface **image)
{
	if ((*image = SDL_CreateRGBSurface(0, 1920, 1080, 32,
			0xFF0000, 0xFF00, 0xFF, 0xFF000000)) == NULL)
	{
		ft_printf("SDL_CreateSurface Error: %s %s\n", SDL_GetError());
		return (ERROR);
	}
	return (SUCCESS);
}
