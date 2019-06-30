/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:36:16 by allallem          #+#    #+#             */
/*   Updated: 2019/06/19 14:14:01 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "SDL_mixer.h"
# include "libft.h"

# define ERROR 0
# define SUCCESS 1

typedef struct		s_window
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_GLContext	cont;
	char					*name;
	int32_t				winpos_x;
	int32_t				winpos_y;
	int32_t				width;
	int32_t				height;
}									t_window;

/*
** initialisation and close
*/

int32_t			ft_init_sdl(uint32_t flags);
int32_t			ft_quit_sdl
		(SDL_Window **win, SDL_Renderer **ren, SDL_Surface **img);
int32_t			ft_init_ttf(void);
void			ft_quit_ttf(void);

/*
** create renderer/win/ect
*/

int32_t			ft_sdl_create_renderer(t_window *win, uint32_t flags);
int32_t			ft_sdl_create_surface(SDL_Surface **image);
int32_t			ft_sdl_create_window(t_window *win, uint32_t flags);

/*
** color and display
*/

void				ft_update_window(t_window *win, SDL_Surface *image);
uint32_t		ft_get_color_sdl2(SDL_Surface *image, int32_t x, int32_t y);

#endif
