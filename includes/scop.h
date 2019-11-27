/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:37:45 by allallem          #+#    #+#             */
/*   Updated: 2019/09/17 14:48:03 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H

# include "libui.h"
# include <time.h>
# include <GL/glew.h>

# define TETA 0.2
# define WIDTH 1920
# define HEIGHT 1080

typedef struct			s_mat
{
	float				*array;
	int					width;
	int					height;
}						t_mat;

typedef struct			s_event
{
	float				interpolate;
	uint8_t				texture;
	uint8_t				line;
	uint8_t				run;
	uint8_t				rotate;
	int32_t				x;
	int32_t				y;
}						t_event;

typedef struct			s_time
{
	uint32_t			last_time;
	uint32_t			current_time;
	uint32_t			ellapsed_time;
}						t_time;

typedef struct			s_transformation
{
	float				rotatex[16];
	float				rotatey[16];
	float				rotatez[16];
	float				rotate[16];
	float				vecs[16];
	float				anglex;
	float				angley;
	float				anglez;
}						t_transformation;

typedef struct			s_scop
{
	t_window			sdl;
	t_event				event;
	t_transformation	trans;
	t_time				time;
	t_mat				*projection;
	float				**point;
	float				*vertices;
	uint32_t			**triangle;
	uint32_t			point_number;
	uint32_t			link_number;
	GLuint				vertex;
	GLuint				frag;
	GLuint				program;
	GLuint				texture_id;
	GLuint				vao;
	GLuint				vbo;
	GLenum				formatinterne;
	GLenum				format;
	SDL_Surface			*texture;
}						t_scop;

/*
** parsing
*/

int32_t					ft_allocate_env(t_scop *env);
int32_t					ft_fill_env(t_scop *env, char *file_name);
char					*ft_loadsource(const char *filename);
void					ft_center(t_scop *env);
void					ft_attribute_vertices(t_scop *env, float *vertices);

/*
** initialisation + running
*/

uint32_t				ft_load_texture(t_scop *env);
void					ft_bind_texture_coord(t_scop *env);
void					ft_bind_color(t_scop *env, uint32_t i, uint32_t j);
uint32_t				ft_scop(t_scop *env, char *name);
uint32_t				ft_run(t_scop *env);
void					ft_update_data(t_scop *env, GLuint program);
void					ft_texture_interpolation(t_scop *env);
t_mat					*ft_mat_perspective(float angle, float ratio,
			float near, float far);

/*
** shader/program functions
*/

uint32_t				ft_create_shader(GLuint *shader, char *file_name,
		GLint compile_status, GLuint options);
uint32_t				ft_create_program(GLuint *program, GLuint *vertex,
	GLuint *frag, GLint compile_status);

/*
** event functions
*/

uint32_t				ft_keys_event(t_scop *env, SDL_Event e,
	const uint8_t *state);

/*
** matrix calculation
*/

void					ft_mat4_multiplication(float *m, float *m1, float *m2);
void					ft_rotate(t_scop *env);

#endif
