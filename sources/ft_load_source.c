/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_source.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allallem <allallem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:03:05 by allallem          #+#    #+#             */
/*   Updated: 2019/08/26 15:03:22 by allallem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

char		*LoadSource(const char *filename)
{
	char *src = NULL;
	FILE *fp = NULL;
	long size;
	long i;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		ft_printf("impossible d'ouvrir le fichier '%s'\n", filename);
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	src = malloc(size + 1);
	if (src == NULL)
	{
		fclose(fp);
		ft_printf("erreur d'allocation de memoire!\n");
		return NULL;
	}
	for (i = 0; i < size; i++)
		src[i] = fgetc(fp);
	src[size] = '\0';
	fclose(fp);
	return src;
}
