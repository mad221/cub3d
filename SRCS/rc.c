/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:54:27 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 19:24:27 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

void		ft_free_sprite(t_sprite *sprite, t_prite *prite)
{
	free(prite);
	free(sprite);
}

void		ft_sprite(t_list *stock)
{
	int			i;
	t_sprite	*sprite;
	t_prite		*prite;

	i = 0;
	prite = malloc(sizeof(t_prite));
	prite->numsprite = ft_count_sprite(stock);
	if (!(sprite = malloc(sizeof(t_sprite) * prite->numsprite)))
		return ;
	if (!(prite->spriteorder = malloc(sizeof(int) * prite->numsprite)))
		return ;
	if (!(prite->spritedistance =
	malloc(sizeof(double) * prite->numsprite)))
		return ;
	ft_place_sprite(stock, sprite);
	ft_order_sprite(sprite, prite, stock);
	ft_free_sprite(sprite, prite);
}

void		ft_rc(t_list *stock)
{
	int		x;
	t_rc	*rc;

	rc = malloc(sizeof(t_rc));
	x = 0;
	while (x < stock->wdw_width)
	{
		ft_set(rc, stock, x);
		ft_pixel(stock, x, 0, (int)((stock->wdw_height / 2)
		- (stock->wdw_height / 4) / rc->perpdualist));
		stock->color = stock->color_floor;
		ft_pixel(stock, x, (int)((stock->wdw_height / 2)
		+ (stock->wdw_height / 4) / rc->perpdualist), stock->wdw_height);
		ft_draw_window(stock, x, rc->drawstart, rc->drawend);
		stock->zbuffer[x] = rc->perpdualist;
		x++;
	}
	ft_sprite(stock);
	free(rc);
}
