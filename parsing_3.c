/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:22:06 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/26 14:10:02 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

static int		ft_init_texture(t_list *stock)
{
	stock->height = 0;
	stock->width = 0;
	stock->mlx_co = mlx_init();
	if ((stock->mlx_wdw = mlx_new_window(stock->mlx_co,
	stock->wdw_width, stock->wdw_height, "HA!")) == 0)
		return (0);
	return (1);
}

int				ft_texture(t_list *stock)
{
	int			i;

	i = -1;
	if (ft_init_texture(stock) == 0 ||
	!(stock->mlx_wall = malloc(sizeof(int*) * 4 + 1)) ||
	!(stock->cast = malloc(sizeof(int *) * 4 + 1)))
		return (0);
	while (++i < 4)
	{
		if (ft_check_i(i, stock) == 0)
			return (0);
		if (((stock->mlx_wall[i] = mlx_xpm_file_to_image(stock->mlx_co,
		&stock->string[ft_bg(stock->string, i)], &stock->width, &stock->height))
		<= 0))
			return (0);
		if (((stock->cast[i] = (int*)mlx_get_data_addr(stock->mlx_wall[i],
		&stock->bitpx, &stock->size_line, &stock->endian)) <= 0))
			return (0);
	}
	return (1);
}

int				ft_color(t_list *stock)
{
	while (get_next_line(stock->fd, &stock->string) &&
	stock->string[0] != 'F' && ft_free(stock))
		;
	if ((stock->color_ciel = ft_convert(stock->string)) == -1)
		return (0);
	while (get_next_line(stock->fd, &stock->string)
	&& stock->string[0] != 'C' && ft_free(stock))
		;
	if ((stock->color_floor = ft_convert(stock->string)) == -1)
		return (0);
	return (1);
}

int				ft_conv(int *array, char *str)
{
	int			i;
	int			s;

	i = -1;
	s = 0;
	while (str[++i])
		if (str[i] != ' ')
		{
			if (ft_isnum(str[i]) == 1)
				array[s] = str[i] - 48;
			if (str[i] == 'N')
				array[s] = 10;
			if (str[i] == 'S')
				array[s] = 11;
			if (str[i] == 'E')
				array[s] = 12;
			if (str[i] == 'O')
				array[s] = 13;
			s++;
		}
	return (s);
}
