/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area_vision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:13:22 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 13:16:46 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void	ft_correct_pos_left(t_list *stock)
{
	double lastdirx;
	double lastplanex;

	lastdirx = stock->dirx;
	stock->dirx = stock->dirx * cos(-stock->rotate_speed)
	- stock->diry * sin(-stock->rotate_speed);
	stock->diry = lastdirx * sin(-stock->rotate_speed) +
	stock->diry * cos(-stock->rotate_speed);
	lastplanex = stock->planex;
	stock->planex = stock->planex * cos(-stock->rotate_speed)
	- stock->planey * sin(-stock->rotate_speed);
	stock->planey = lastplanex * sin(-stock->rotate_speed)
	+ stock->planey * cos(-stock->rotate_speed);
}

void	ft_correct_pos_right(t_list *stock)
{
	double lastdirx;
	double lastplanex;

	lastdirx = stock->dirx;
	stock->dirx = stock->dirx * cos(stock->rotate_speed)
	- stock->diry * sin(stock->rotate_speed);
	stock->diry = lastdirx * sin(stock->rotate_speed) +
	stock->diry * cos(stock->rotate_speed);
	lastplanex = stock->planex;
	stock->planex = stock->planex * cos(stock->rotate_speed)
	- stock->planey * sin(stock->rotate_speed);
	stock->planey = lastplanex * sin(stock->rotate_speed)
	+ stock->planey * cos(stock->rotate_speed);
}
