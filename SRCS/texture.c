/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:12:06 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/01 16:12:35 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int				ft_texture(t_list *stock)
{
	if (ft_path_wall(stock) == 0)
		return (0);
	return (1);
}

int				ft_texturing(t_list *stock)
{
	int			i;

	i = -1;
	if (!(stock->mlx_wall = malloc(sizeof(int*) * 4)) ||
	!(stock->cast = malloc(sizeof(int *) * 4)))
		return (0);
	while (++i < 4)
	{
		if (((stock->mlx_wall[i] = mlx_xpm_file_to_image(stock->mlx_co,
		stock->path_wall[i], &stock->width, &stock->height))
		<= 0))
			return (0);
		if (((stock->cast[i] = (int*)mlx_get_data_addr(stock->mlx_wall[i],
		&stock->bitpx, &stock->size_line, &stock->endian)) <= 0))
			return (0);
	}
	return (1);
}
