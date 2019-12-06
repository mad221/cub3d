/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:04:47 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/06 12:47:50 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int	ft_redcross(t_list *stock)
{
	int i;

	i = -1;
	free(stock->zbuffer);
	free(stock->file);
	while (++i < 4)
	{
		free(stock->mlx_wall[i]);
		free(stock->path_wall[i]);
		free(stock->cast[i]);
	}
	free(stock->mlx_wall);
	free(stock->cast);
	free(stock->path_wall);
	free(stock->path_sprite);
	i = -1;
	while (++i < stock->map_height)
		free(stock->map[i]);
	free(stock->map);
	mlx_destroy_window(stock->mlx_co, stock->mlx_wdw);
	free(stock);
	system("leaks cub3D");
	exit(EXIT_SUCCESS);
	return (0);
}
