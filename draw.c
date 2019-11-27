/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:50:37 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 19:24:38 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

int		limit(int a, int limit)
{
	if (a < 0)
		return (0);
	return (a > limit ? limit : a);
}

void	ft_drawline(double y0, double dx, double dy, t_list *stock)
{
	double	y;
	double	m;
	int		x1;
	int		x;

	y = y0;
	m = dy / dx;
	x1 = (stock->wdw_height / 4 + 10) + dx;
	x = stock->wdw_height / 4 + 10;
	if (x < x1)
		while (x < x1)
		{
			stock->data_wdw[(int)y * stock->wdw_width + x] = 169169169;
			x++;
			y = y + m;
		}
	else
		while (x > x1)
		{
			stock->data_wdw[(int)y * stock->wdw_width + x] = 169169169;
			x--;
			y = y - m;
		}
}

void	ft_pixel(t_list *stock, int x, int ymin, int ymax)
{
	while (ymin < ymax)
	{
		stock->data_wdw[limit(ymin * stock->wdw_width + x,
		stock->wdw_height * stock->wdw_width - 1)] = stock->color;
		ymin++;
	}
}

void	ft_draw_window(t_list *stock, int x, int ymin, int ymax)
{
	int i;
	int pix_img;
	int pix_wall;
	int d;

	i = 0;
	while (ymin < ymax && ymax < stock->wdw_height)
	{
		d = ymin * 256 - stock->wdw_height * 128 + stock->lineheight * 128;
		pix_img = limit(ymin * stock->wdw_width + x,
		stock->wdw_height * stock->wdw_width - 1);
		pix_wall = ((d * stock->height) / stock->lineheight) / 256;
		stock->data_wdw[pix_img] = stock->cast[stock->side]
		[stock->height * pix_wall + stock->texx];
		ymin += 1;
	}
}
