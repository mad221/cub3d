/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:41:43 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 10:48:01 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	ft_place_sprite(t_list *stock, t_sprite *sprite)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (y < stock->map_height)
	{
		x = 0;
		while (x < stock->lenstring)
		{
			if (stock->map[y][x] == 2)
			{
				sprite[i].x = x + 0.5;
				sprite[i].y = y + 0.5;
				i++;
			}
			x++;
		}
		y++;
	}
}

int		ft_count_sprite(t_list *stock)
{
	int x;
	int y;
	int count;

	count = 0;
	y = 0;
	while (y < stock->map_height)
	{
		x = 0;
		while (x < stock->lenstring)
		{
			if (stock->map[y][x] == 2)
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_combsort(int *order, double *dist, int amount)
{
	int		i;
	int		temp;
	double	temp2;
	int		s;

	s = -1;
	i = 0;
	while (++s < amount * 4)
	{
		while (i < amount - 1)
		{
			if (dist[i] < dist[i + 1])
			{
				temp2 = dist[i + 1];
				dist[i + 1] = (dist[i] < 0 ? fabs(dist[i]) + 2 : dist[i]);
				dist[i] = (temp2 < 0 ? fabs(temp2) + 2 : temp2);
				temp = order[i + 1];
				order[i + 1] = order[i];
				order[i] = temp;
				i = 0;
			}
			else
				i++;
		}
	}
}
