/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:14:41 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/28 12:27:57 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"

static int	ft_init_value(t_list *stock)
{
	stock->rotate_speed = 0.20;
	stock->speed = 0.40;
	stock->angle = 3;
	if (!(stock->zbuffer = malloc(sizeof(double) * stock->wdw_width)))
		return (0);
	return (1);
}

int			main(int ac, char **argv)
{
	t_list *stock;

	if (!(stock = malloc(sizeof(t_list))))
		return (0);
	if ((stock->mlx_co = mlx_init()) == 0)
		return (0);
	if (ft_message(ft_parsing(stock), stock) != 1)
		return (0);
	if ((ft_init_value(stock)) == 0)
		return (0);
	if ((stock->mlx_wdw = mlx_new_window(stock->mlx_co,
	stock->wdw_width, stock->wdw_height, "AH")) == 0)
		return (0);
	if (ac == 2)
	{
		ft_save(argv[ac - 1], stock);
		return (0);
	}
	ft_init_value(stock);
	mlx_key_hook(stock->mlx_wdw, ft_deal_key, stock);
	mlx_hook(stock->mlx_wdw, 17, 1L << 17, &ft_redcross, stock);
	mlx_string_put(stock->mlx_co, stock->mlx_wdw, stock->wdw_width / 2.25,
	stock->wdw_height / 2, 225300, "PRESS ANY KEY TO LAUNCH CUB3D");
	mlx_loop(stock->mlx_co);
	return (0);
}
