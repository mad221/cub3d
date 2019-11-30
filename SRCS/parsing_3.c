/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 13:22:06 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/30 17:22:30 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

int		ft_init_texture(t_list *stock)
{
	stock->nbr_texture = 0;

	if ((stock->mlx_co = mlx_init()) == 0)
		return (0);
	if ((stock->mlx_wdw = mlx_new_window(stock->mlx_co,
		stock->wdw_width, stock->wdw_height, "HA!")) == 0)
		return (0);
	ft_texturing(stock);
	ft_spriting(stock);
	return (1);
}

int		ft_cpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

int			ft_path_wall(t_list *stock)
{
	int i;

	i = -1;
	if (!(stock->path_wall = malloc(sizeof(char*) * 4 + 1)))
		return (0);
	while (++i < 4)
	{
		if (ft_check_i(i, stock) == 0 && ft_free(stock) == 0)
			return (0);
		if (!(stock->path_wall[i] = malloc(sizeof(char)
		* ft_strlen(&stock->string[ft_bg(stock->string, i)]) + 2)))
			return (0);
		ft_cpy(stock->path_wall[i], &stock->string[ft_bg(stock->string, i)]);
		ft_free(stock);
		if (open(stock->path_wall[i], O_RDONLY) < 0)
			return (0);
		stock->number_path = i+1;
	}
	return (1);
}
int 			ft_texture(t_list *stock)
{
	if (ft_path_wall(stock) == 0)
		return (0);
	return (1);
}

int				ft_texturing(t_list *stock)
{
	int			i;

	i = -1;
	if (!(stock->mlx_wall = malloc(sizeof(int*) * 4)) ||
	!(stock->cast = malloc(sizeof(int *) * 4)))
		return (0);
	while (++i < 4)
	{
		if (((stock->mlx_wall[i] = mlx_xpm_file_to_image(stock->mlx_co,
		stock->path_wall[i], &stock->width, &stock->height))
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
		free(stock->string);
	if ((stock->color_ciel = ft_convert(stock->string)) == -1)
		return (ft_free(stock) * 0);
	ft_free(stock);
	while (get_next_line(stock->fd, &stock->string)
	&& stock->string[0] != 'C')
		free(stock->string);
	if ((stock->color_floor = ft_convert(stock->string)) == -1)
		return (ft_free(stock) * 0);
	free(stock->string);
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
