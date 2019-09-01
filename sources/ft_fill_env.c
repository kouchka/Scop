/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:24:24 by allallem          #+#    #+#             */
/*   Updated: 2019/09/01 14:43:40 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char				*ft_parse_data(char *line, t_scop *env)
{
	static uint32_t i = 0;
	static uint32_t j = 0;
	uint32_t				tmp;

	if (line[0] == '#' || line[0] == 's' || line[0] == 'o'
		|| ft_strstr(line, "mtllib") || ft_strstr(line, "usemtl"))
		return (0);
	if (i < env->point_number && line[0] == 'v'
		&& (sscanf(line, "v %f %f %f", &env->point[i][0],
		&env->point[i][1], &env->point[i][2])) != 3)
		return ("Error while taking point coordinates");
	if ((j < env->link_number && line[0] == 'f'
		&& sscanf(line, "f %u %u %u", &env->triangle[j][0],
		&env->triangle[j][1], &env->triangle[j][2]) != 3)
		|| (env->triangle[j][0] > env->point_number)
		|| (env->triangle[j][1] > env->point_number)
		|| (env->triangle[j][2] > env->point_number))
		return ("Error while taking surface coordinates");
	if ((j + 1 < env->link_number
		&& line[0] == 'f' && sscanf(line, "f %u %u %u %u",
		&env->triangle[j + 1][0], &tmp, &env->triangle[j + 1][1],
		&env->triangle[j + 1][2]) == 4))
	{
		j++;
		if ((env->triangle[j][0] > env->point_number)
		|| (env->triangle[j][1] > env->point_number)
		|| (env->triangle[j][2] > env->point_number))
			return ("Error while taking surface coordinates");
	}
	if (line[0] == 'v')
		i++;
	if (line[0] == 'f')
		j++;
	return (0);
}

int32_t			ft_fill_env(t_scop *env, char *file_name)
{
	FILE *file;
	char line[100];
	char *result;

	if (!(file = fopen(file_name, "r")))
	{
		ft_printf("Cannot open %s : fopen failed\n", file_name);
		return (0);
	}
	while (fgets(line, 60, file) > 0)
	{
		if ((result = ft_parse_data(line, env)))
		{
			ft_printf("%s\nline : %s\n", result, line);
			fclose(file);
			return (0);
		}
	}
	fclose(file);
	return (1);
}
