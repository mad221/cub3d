/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:50:53 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 13:36:12 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

int			ft_search_map(t_list *stock, int *i)
{
	int	map;
	int	status;

	map = 0;
	while ((status = get_next_line(stock->fd, &stock->string)))
	{
		if (stock->string[0] == '1' && !map)
			map = 1;
		if (map && stock->string[0] == '1')
			*i += 1;
		ft_free(stock);
	}
	close(stock->fd);
	stock->map_height = *i;
	*i += 1;
	if (ft_open(stock) == 0)
		return (0);
	return (1);
}

static void	ft_player_1(t_list *stock, int dir)
{
	if (dir == 12)
	{
		stock->dirx = 1;
		stock->diry = 0;
		stock->planex = 0.00;
		stock->planey = -1.20;
	}
	if (dir == 13)
	{
		stock->dirx = -1;
		stock->diry = 0;
		stock->planex = 0.0;
		stock->planey = 1.20;
	}
}

void		ft_player(t_list *stock, int dir, int y, int x)
{
	stock->x = x;
	stock->y = y;
	if (dir == 10)
	{
		stock->dirx = 0;
		stock->diry = -1;
		stock->planex = -1.20;
		stock->planey = 0.0;
	}
	if (dir == 11)
	{
		stock->dirx = 0;
		stock->diry = 1;
		stock->planex = 1.20;
		stock->planey = 0.0;
	}
	ft_player_1(stock, dir);
	stock->map[y][x] = 0;
}

int			ft_init_pos(t_list *stock)
{
	int	i;
	int	s;

	i = -1;
	while (++i < stock->map_height)
	{
		s = -1;
		while (++s < stock->lenstring)
		{
			if (stock->map[i][s] > 2 || stock->map[i][s] < 0)
				stock->pos_ok += 1;
			if (stock->map[i][s] == 10)
				(ft_player(stock, 10, i, s));
			if (stock->map[i][s] == 11)
				(ft_player(stock, 11, i, s));
			if (stock->map[i][s] == 12)
				(ft_player(stock, 12, i, s));
			if (stock->map[i][s] == 13)
				(ft_player(stock, 13, i, s));
		}
	}
	if (stock->pos_ok == 0)
		return (-10);
	return (stock->pos_ok != 1 ? -9 : 1);
}
