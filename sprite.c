/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:38:57 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 13:39:03 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void		ft_order_sprite(t_sprite *sprite, t_prite *prite, t_list *stock)
{
	int		i;

	i = 0;
	while (i < prite->numsprite)
	{
		prite->spriteorder[i] = i;
		prite->spritedistance[i] = ((stock->x - sprite[i].x) * (stock->x -
		sprite[i].x) + (stock->y - sprite[i].y * (stock->y - sprite[i].y)));
		i++;
	}
	ft_combsort(prite->spriteorder, prite->spritedistance, prite->numsprite);
	ft_set_sprite(sprite, prite, stock);
}

static void	ft_set_prite(t_sprite *sprite, t_prite *prite, t_list *stock, int i)
{
	prite->spritx = sprite[prite->spriteorder[i]].x - stock->x;
	prite->sprity = sprite[prite->spriteorder[i]].y - stock->y;
	prite->invdet = 1.0 / (stock->planex * stock->diry
	- stock->dirx * stock->planey);
	prite->transformx = prite->invdet * (stock->diry * prite->spritx
	- stock->dirx * prite->sprity);
	prite->transformy = prite->invdet * (-stock->planey * prite->spritx
	+ stock->planex * prite->sprity);
	prite->spritescreen = (int)((stock->wdw_width / 2)
	* (1 + prite->transformx / prite->transformy));
	prite->spriteheight = abs((int)(stock->wdw_height
	/ 2 / prite->transformy));
	prite->drawstarty = -prite->spriteheight / 2 + stock->wdw_height / 2;
}

static void	ft_set_draw(t_prite *prite, t_list *stock)
{
	if (prite->drawstarty < 0)
		prite->drawstarty = 0;
	prite->drawendy = prite->spriteheight / 2 + stock->wdw_height / 2;
	if (prite->drawendy >= stock->wdw_height)
		prite->drawendy = stock->wdw_height - 1;
	prite->spritewidth = abs((int)((stock->wdw_height / 2) /
	(prite->transformy)));
	prite->drawstartx = -prite->spritewidth / 2 + prite->spritescreen;
	if (prite->drawstartx < 0)
		prite->drawstartx = 0;
	prite->drawendx = prite->spritewidth / 2 + prite->spritescreen;
	if (prite->drawendx >= stock->wdw_width)
		prite->drawendx = stock->wdw_width - 1;
	prite->lenght = prite->drawstartx;
}

static void	ft_draw_prite(t_prite *prite, t_list *stock)
{
	while (prite->y < prite->drawendy)
	{
		prite->d = (prite->y) * 256 - stock->wdw_height *
		128 + prite->spriteheight * 128;
		prite->texy = ((prite->d * stock->sprite_height)
		/ prite->spriteheight) / 256;
		if (stock->sprite_data[stock->sprite_height * prite->texy + prite->texx]
		!= stock->sprite_data[1])
			stock->data_wdw[prite->y * stock->wdw_width + prite->lenght] =
			stock->sprite_data[stock->sprite_width * prite->texy + prite->texx];
		prite->y++;
	}
}

void		ft_set_sprite(t_sprite *sprite, t_prite *prite, t_list *stock)
{
	int i;

	i = -1;
	while (++i < prite->numsprite)
	{
		ft_set_prite(sprite, prite, stock, i);
		ft_set_draw(prite, stock);
		while (prite->lenght < prite->drawendx)
		{
			prite->texx = (int)(256 * (prite->lenght - (-prite->spritewidth / 2
			+ prite->spritescreen)) * stock->sprite_width
			/ prite->spritewidth / 256);
			prite->y = prite->drawstarty;
			if (prite->transformy > 0 && prite->y > 0 && prite->lenght > 0 &&
			prite->lenght < stock->wdw_width && prite->transformy
			< stock->zbuffer[prite->lenght])
				ft_draw_prite(prite, stock);
			prite->lenght++;
		}
	}
}
