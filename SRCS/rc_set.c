/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:58:21 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 13:39:35 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static void	ft_set_draw(t_rc *rc, t_list *stock)
{
	rc->wallx -= (int)rc->wallx;
	stock->texx = (int)(rc->wallx * (double)(stock->sprite_height));
	stock->lineheight = (stock->wdw_height / 2) / rc->perpdualist;
	rc->drawstart = -stock->lineheight / 2 + stock->wdw_height / 2;
	if (rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = stock->lineheight / 2 + stock->wdw_height / 2;
	if (rc->drawend >= stock->wdw_height)
		rc->drawend = stock->wdw_height - 1;
	stock->color = stock->color_ciel;
}

static void	ft_set_side(t_rc *rc, t_list *stock)
{
	if (rc->side == 0)
	{
		rc->perpdualist = (rc->mapx - stock->x + (1 -
		rc->stepx) / 2) / rc->dirx;
		if (rc->stepx < 0)
			stock->side = 2;
		else
			stock->side = 1;
	}
	else
	{
		rc->perpdualist = (rc->mapy - stock->y + (1 - rc->stepy) / 2)
		/ rc->diry;
		if (rc->stepy < 0)
			stock->side = 0;
		else
			stock->side = 3;
	}
	if (rc->side == 0)
		rc->wallx = stock->y + rc->perpdualist * rc->diry;
	else
		rc->wallx = stock->x + rc->perpdualist * rc->dirx;
}

static void	ft_set_hit(t_rc *rc, t_list *stock)
{
	rc->hit = 0;
	while (rc->hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (stock->map[rc->mapy][rc->mapx] == 1)
			rc->hit = 1;
	}
}

static void	ft_set_moving(t_rc *rc, t_list *stock)
{
	if (rc->dirx < 0)
	{
		rc->stepx = -1;
		rc->sidedistx = (stock->x - rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1 - stock->x) * rc->deltadistx;
	}
	if (rc->diry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (stock->y - rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1 - stock->y) * rc->deltadisty;
	}
}

void		ft_set(t_rc *rc, t_list *stock, int x)
{
	rc->ratio = 2 * x / (double)(stock->wdw_width) - 1;
	rc->dirx = stock->dirx + stock->planex * rc->ratio;
	rc->diry = stock->diry + stock->planey * rc->ratio;
	rc->mapx = (int)stock->x;
	rc->mapy = (int)stock->y;
	rc->deltadistx = sqrt(1 + ((rc->diry * rc->diry) / (rc->dirx * rc->dirx)));
	rc->deltadisty = sqrt(1 + ((rc->dirx * rc->dirx) / (rc->diry * rc->diry)));
	ft_set_moving(rc, stock);
	ft_set_hit(rc, stock);
	ft_set_side(rc, stock);
	ft_set_draw(rc, stock);
}
