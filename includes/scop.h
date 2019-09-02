/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:37:45 by allallem          #+#    #+#             */
/*   Updated: 2019/09/02 16:45:17 by allallem         ###   ########.fr       */
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
	float		interpolate;
	uint8_t texture;
	uint8_t run;
	uint8_t rotate;
	int32_t x;
	int32_t y;

}									t_event;

typedef struct		s_time
{
	uint32_t		last_time;
	uint32_t		current_time;
	uint32_t		ellapsed_time;
}									t_time;

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
	t_time						time;
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
char				*LoadSource(const char *filename);
void				ft_center(t_scop *env);

/*
** initialisation + running
*/

uint32_t		ft_scop(t_scop *env, char *name);
uint32_t		ft_run(t_scop *env);
void				ft_update_data(t_scop *env, GLuint program);

/*
** shader/program functions
*/

uint32_t		ft_create_shader(GLuint *shader, char *file_name,
		GLint compile_status, GLuint options);
uint32_t		ft_create_program(GLuint *program, GLuint *vertex, GLuint *frag,
		GLint compile_status);

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
