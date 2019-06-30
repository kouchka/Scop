/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:54:18 by allallem          #+#    #+#             */
/*   Updated: 2019/06/23 16:14:37 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// __attribute__((destructor))
// void			test_leaks()
// {
// 	while (1);
// }

void			ft_free_env(t_scop *env)
{
	uint32_t j;

	j = 0;
	while (j < env->point_number)
	{
		free(env->point[j]);
		j++;
	}
	j = 0;
	while (j < env->link_number)
	{
		free(env->triangle[j]);
		j++;
	}
	free(env->point);
	free(env->triangle);
}

char			*ft_parse_line(char *line, t_scop *env)
{
	float			tmp;
	int32_t		tmp2;

	if (line[0] == 'v' && (sscanf(line, "v %f %f %f",
		&tmp, &tmp, &tmp)) == 3)
	{
		env->point_number++;
		return (0);
	}
	if (line[0] == 'f' && (sscanf(line, "f %d %d %d",
		&tmp2, &tmp2, &tmp2)) == 3)
	{
		env->link_number++;
		return (0);
	}
	if (line[0] == '#' || line[0] == 's' || line[0] == 'o'
		|| ft_strstr(line, "mtllib") || ft_strstr(line, "usemtl"))
		return (0);
	return ("Error while parsing lines in .obj\n");
}

int32_t			ft_parse_obj(char *file_name, t_scop *env)
{
	FILE	*file;
	char line[60];
	char *result;

	if (!(file = fopen(file_name, "r")))
	{
		ft_printf("Cannot open %s : fopen failed\n", file_name);
		return (0);
	}
	while (fgets(line, 60, file) > 0)
	{
		if ((result = ft_parse_line(line, env)))
		{
			ft_printf("%s\nline : %s\n", result, line);
			fclose(file);
			return (0);
		}
	}
	fclose(file);
	return (1);
}

int32_t			main(int argc, char **argv)
{
	t_scop		env;

	if (argc > 1)
	{
		ft_bzero(&env, sizeof(t_scop));
		if (ft_parse_obj(argv[1], &env) && env.point_number && env.link_number
			&& ft_allocate_env(&env) && ft_fill_env(&env, argv[1]))
		{
			// ft_print_table(&env);
			ft_scop(&env, argv[1]);
		}
		else
			ft_printf("Error while parsing object\n");
	}
	else
		ft_printf("usage : ./scop file.obj\n");
	ft_free_env(&env);
	return (SUCCESS);
}
