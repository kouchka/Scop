/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:37:45 by allallem          #+#    #+#             */
/*   Updated: 2019/08/26 14:15:26 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libui.h"
# include <time.h>
# include <GL/glew.h>

# define TETA 0.2

typedef struct		s_event
{
	uint8_t run;
}									t_event;

typedef struct		s_transformation
{
	float				rotatex[16];
	float				rotatey[16];
	float				rotatez[16];
	float				rotate[16];
	float				vecs[16];
	float				anglex;
	float				angley;
	float				anglez;
}									t_transformation;

typedef struct			s_scop
{
	t_window					sdl;
	t_event						event;
	t_transformation	trans;
	float							**point;
	uint32_t					**triangle;
	uint32_t					point_number;
	uint32_t					link_number;
}										t_scop;

/*
** parsing
*/

int32_t			ft_allocate_env(t_scop *env);
int32_t			ft_fill_env(t_scop *env, char *file_name);

/*
** initialisation + running
*/

uint32_t		ft_scop(t_scop *env, char *name);
uint32_t		ft_run(t_scop *env);

/*
** event functions
*/

uint32_t		ft_keys_event(t_scop *env, SDL_Event e, const uint8_t *state);

/*
** matrix calculation
*/

void				ft_mat4_multiplication(float *m, float *m1, float *m2);

/*
** functions to remove (used for tests)
*/

void				ft_print_table(t_scop *env);
void				ft_check_mat4(float *mat4);

#endif
