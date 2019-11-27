/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bind_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:36:36 by allallem          #+#    #+#             */
/*   Updated: 2019/09/04 10:47:19 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void					ft_assign_color(float *color, uint32_t j)
{
	if (j % 3 == 1)
		*color = 0.0;
	if (j % 3 == 2)
		*color = 0.2;
	if (j % 3 == 0)
		*color = 0.4;
}

void					ft_bind_color(t_scop *env, uint32_t i, uint32_t j)
{
	float	c_buff[env->link_number * 9];
	GLuint	colorbuffer;
	float	color;

	while (j < env->link_number && ((i + 9) < (env->link_number * 9) + 1))
	{
		ft_assign_color(&color, j);
		c_buff[i] = color;
		c_buff[i + 1] = color;
		c_buff[i + 2] = color;
		c_buff[i + 3] = color;
		c_buff[i + 4] = color;
		c_buff[i + 5] = color;
		c_buff[i + 6] = color;
		c_buff[i + 7] = color;
		c_buff[i + 8] = color;
		i += 9;
		j++;
	}
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(c_buff), c_buff, GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
}

void					ft_bind_texture_coord(t_scop *env)
{
	float		c_buff[env->link_number * 9];
	GLuint		texturebuffer;
	uint32_t	i;
	uint32_t	j;

	i = 0;
	j = 0;
	while (j < env->link_number && ((i + 9) < (env->link_number * 9)))
	{
		c_buff[i] = 0.0;
		c_buff[i + 1] = 0.0;
		c_buff[i + 2] = 1.0;
		c_buff[i + 3] = 0.0;
		c_buff[i + 4] = 0.5;
		c_buff[i + 5] = 1.0;
		i += 6;
		j++;
	}
	glGenBuffers(1, &texturebuffer);
	glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(c_buff), c_buff, GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, texturebuffer);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_TRUE, 2 * sizeof(GL_FLOAT),
		(GLvoid *)(3 * sizeof(GL_FLOAT)));
}
