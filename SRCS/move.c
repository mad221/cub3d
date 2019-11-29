/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:57:57 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/28 15:40:58 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static void	ft_forward(t_list *stock)
{
	if (stock->map[(int)(stock->y + stock->diry * stock->speed)]
	[(int)(stock->x)] == 0)
		stock->y += stock->diry * stock->speed;
	if (stock->map[(int)(stock->y)]
	[(int)(stock->x + stock->dirx * stock->speed)] == 0)
		stock->x += stock->dirx * stock->speed;
}

static void	ft_backward(t_list *stock)
{
	if (stock->map[(int)(stock->y - stock->diry * stock->speed)]
	[(int)(stock->x)] == 0)
		stock->y -= stock->diry * stock->speed;
	if (stock->map[(int)(stock->y)]
	[(int)(stock->x - stock->dirx * stock->speed)] == 0)
		stock->x -= stock->dirx * stock->speed;
}

static void	ft_rightward(t_list *stock)
{
	if (stock->map[(int)(stock->y - stock->dirx * stock->speed)]
	[(int)(stock->x)] == 0)
		stock->y += -stock->dirx * stock->speed;
	if (stock->map[(int)(stock->y)]
	[(int)(stock->x + stock->diry * stock->speed)] == 0)
		stock->x += stock->diry * stock->speed;
}

static void	ft_leftward(t_list *stock)
{
	if (stock->map[(int)(stock->y + stock->dirx * stock->speed)]
	[(int)(stock->x)] == 0)
		stock->y -= -stock->dirx * stock->speed;
	if (stock->map[(int)(stock->y)]
	[(int)(stock->x - stock->diry * stock->speed)] == 0)
		stock->x -= stock->diry * stock->speed;
}

void		ft_position(int key, t_list *stock)
{
	if (key == 123)
	{
		stock->angle += stock->rotate_speed;
		ft_correct_pos_right(stock);
	}
	if (key == 124)
	{
		stock->angle -= stock->rotate_speed;
		ft_correct_pos_left(stock);
	}
	if (key == 13)
		ft_forward(stock);
	if (key == 1)
		ft_backward(stock);
	if (key == 2)
		ft_rightward(stock);
	if (key == 0)
		ft_leftward(stock);
}
