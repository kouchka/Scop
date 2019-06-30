/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:01:07 by allallem          #+#    #+#             */
/*   Updated: 2019/06/19 14:14:07 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int32_t		ft_init_ttf(void)
{
	if (TTF_Init() == -1)
	{
		ft_printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		return (ERROR);
	}
	return (SUCCESS);
}

int32_t		ft_init_sdl(uint32_t flags)
{
	if (SDL_Init(flags) != 0)
	{
		ft_printf("Unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();
		return (ERROR);
	}
	return (SUCCESS);
}
