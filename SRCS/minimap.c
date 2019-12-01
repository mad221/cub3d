/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:49:21 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/01 16:18:54 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	ft_compass(t_list *stock)
{
	int i;

	i = -1;
	stock->color = 155122144;
	while (i++ < 50)
		ft_pixel(stock, stock->wdw_height / 4 - 10 + i, 5, 20);
	stock->color = 555;
	ft_drawline(10, stock->x + cos(stock->angle)
	* 13, stock->y + sin(stock->angle) * 13, stock);
	ft_drawline(11, stock->x + cos(stock->angle)
	* 15, stock->y + sin(stock->angle) * 15, stock);
	ft_drawline(12, stock->x + cos(stock->angle)
	* 13, stock->y + sin(stock->angle) * 13, stock);
}

void	ft_miniwall(int y, int x, t_list *stock)
{
	int square_x;
	int square_y;
	int i;
	int s;
	int color;

	if ((int)stock->x == x && (int)stock->y == y)
	{
		color = 1234567890;
		ft_compass(stock);
	}
	else
		color = 111;
	square_x = 10;
	square_y = 10;
	i = -1;
	mlx_clear_window(stock->mlx_co, stock->mlx_wdw);
	while (++i < square_y)
	{
		s = -1;
		while (++s < square_x)
			stock->data_wdw[x * square_x + s + (y * square_y + i)
			* stock->wdw_width] = color;
	}
}

void	ft_minimap(int **map, t_list *stock)
{
	int x;
	int y;

	y = -1;
	while (++y < stock->map_height && stock->map_height * 10
	< stock->wdw_width / 4)
	{
		x = -1;
		while (++x < stock->lenstring)
		{
			if (map[y][x] == 1 || (x == (int)stock->x && (int)stock->y == y))
				if (stock->wdw_height > 600 && stock->wdw_width > 500)
					ft_miniwall(y, x, stock);
		}
	}
}

int		ft_errormap(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isnum(str[i]) == 0 && str[i] != ' ' && str[i] != 'E'
		&& str[i] != 'N' && str[i] != 'S' && str[i] != 'O')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
