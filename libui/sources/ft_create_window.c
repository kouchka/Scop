/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:06:31 by allallem          #+#    #+#             */
/*   Updated: 2019/06/19 13:06:52 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		ft_sdl_create_window(t_window *win, uint32_t flags)
{
	if ((win->win = SDL_CreateWindow(win->name, win->winpos_x, win->winpos_y,
		win->width, win->height, flags)) == NULL)
	{
		ft_printf("Could not create window: %s\n", SDL_GetError());
		return (ERROR);
	}
	return (SUCCESS);
}
