/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:03:05 by allallem          #+#    #+#             */
/*   Updated: 2019/09/03 13:38:02 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char		*ft_close(FILE *fp)
{
	fclose(fp);
	ft_printf("erreur d'allocation de memoire!\n");
	return (NULL);
}

char		*ft_loadsource(const char *filename)
{
	char *src;
	FILE *fp;
	long size;
	long i;

	fp = fopen(filename, "r");
	if (fp == NULL)
		return (NULL);
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	src = malloc(size + 1);
	if (src == NULL)
		return (ft_close(fp));
	i = 0;
	while (i < size)
	{
		src[i] = fgetc(fp);
		i++;
	}
	src[size] = '\0';
	fclose(fp);
	return (src);
}
