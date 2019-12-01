/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:14:41 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/01 16:57:54 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

static int	ft_init_value(t_list *stock)
{
	ft_correct_resolution(stock);
	stock->rotate_speed = 0.20;
	stock->speed = 0.40;
	stock->angle = 3;
	if (!(stock->zbuffer = malloc(sizeof(double) * stock->wdw_width)))
		return (0);
	ft_init_texture(stock);
	stock->x += 0.1;
	stock->y += 0.1;
	return (1);
}

int			ft_stock_name(char *str, t_list *stock)
{
	int i;
	int s;

	s = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	stock->file = malloc(sizeof(char) * ft_strlen(str) - i + 1);
	while (str[i])
	{
		stock->file[s] = str[i];
		i++;
		s++;
	}
	return (1);
}

int			ft_file(char *str1, char *type, t_list *stock)
{
	int i;

	i = 0;
	while (str1[ft_strlen(str1) - i] == type[ft_strlen(type) - i])
	{
		if (type[ft_strlen(type) - i] == '.')
			return (ft_stock_name(str1, stock));
		i++;
	}
	ft_putstr("Error\nNot A .cub File\n");
	return (0);
}

int			ft_free_stock(t_list *stock)
{
	free(stock);
	return (0);
}

int			main(int ac, char **argv)
{
	t_list *stock;

	if (!(stock = malloc(sizeof(t_list))))
		return (0);
	if (ac == 1)
		ft_putstr("Error\nToo Few Arguments\n");
	if (ac == 1 || ft_file(argv[1], ".cub", stock) == 0)
		return (ft_free_stock(stock));
	if (ft_message(ft_parsing(stock), stock) != 1)
		return (0);
	if ((ft_init_value(stock)) == 0)
		return (0);
	if (ac == 3)
		ft_save(argv[2], stock);
	if (ac == 2)
	{
		mlx_key_hook(stock->mlx_wdw, ft_deal_key, stock);
		mlx_hook(stock->mlx_wdw, 17, 1L << 17, &ft_redcross, stock);
		mlx_string_put(stock->mlx_co, stock->mlx_wdw, stock->wdw_width / 2.25,
		stock->wdw_height / 2, 225300, "PRESS ANY KEY TO START");
		mlx_loop(stock->mlx_co);
	}
	else
		ft_putstr("ERROR/Too Many Aurguments\n");
	return (EXIT_SUCCESS);
}
