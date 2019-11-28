/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:47:22 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/28 10:05:27 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	ft_mlx_stop(t_list *stock)
{
	int i;

	i = -1;
	free(stock->string);
	free(stock->zbuffer);
	while (++i < 4)
		free(stock->mlx_wall[i]);
	free(stock->mlx_wall);
	i = -1;
	while (++i < stock->map_height)
		free(stock->map[i]);
	free(stock->map);
	mlx_clear_window(stock->mlx_co, stock->mlx_wdw);
	mlx_destroy_window(stock->mlx_co, stock->mlx_wdw);
	free(stock);
	exit(1);
}

int		ft_deal_key(int key, void *param)
{
	t_list *stock;

	stock = param;
	stock->new_wdw = mlx_new_image(stock->mlx_co,
	stock->wdw_width, stock->wdw_height);
	stock->data_wdw = (int*)mlx_get_data_addr(stock->new_wdw,
	&stock->bit_pix_wdw, &stock->size_line_wdw, &stock->endian_wdw);
	if (key == 53)
		ft_mlx_stop(stock);
	if (key == 13 || (key >= 0 && key <= 2) || key == 123 || key == 124)
		ft_position(key, stock);
	ft_rc(stock);
	ft_minimap(stock->map, stock);
	mlx_put_image_to_window(stock->mlx_co,
	(void*)stock->mlx_wdw, (void*)stock->new_wdw, 0, 0);
	return (0);
}

void	ft_move(int nb, t_list *stock)
{
	double walk;

	walk = stock->x + (stock->speed * cos(stock->angle)) * nb;
	if (stock->map[(int)(stock->y)][(int)walk] == 0)
		stock->x = walk;
	walk = stock->y + (stock->speed * sin(stock->angle)) * nb;
	if (stock->map[(int)walk][(int)stock->x] == 0)
		stock->y = walk;
}
