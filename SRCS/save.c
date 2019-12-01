/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:51:48 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/01 16:30:45 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

static int	ft_cmp(char *str, char *str1)
{
	int i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

static void	ft_write(t_list *stock)
{
	int fd;

	fd = open(SCREENSHOT_PATH, O_CREAT);
	close(fd);
	create_bmp(stock);
}

static void	ft_gen(t_list *stock)
{
	ft_rc(stock);
	ft_minimap(stock->map, stock);
	ft_write(stock);
}

static void	ft_end_save(t_list *stock)
{
	int i;

	i = -1;
	free(stock->zbuffer);
	free(stock->file);
	while (++i < 4)
	{
		free(stock->mlx_wall[i]);
		free(stock->path_wall[i]);
		free(stock->cast[i]);
	}
	free(stock->mlx_wall);
	free(stock->cast);
	free(stock->path_wall);
	free(stock->path_sprite);
	i = -1;
	while (++i < stock->map_height)
		free(stock->map[i]);
	free(stock->map);
	free(stock->sprite);
	free(stock->sprite_data);
	mlx_destroy_image(stock->mlx_co, stock->new_wdw);
	mlx_destroy_window(stock->mlx_co, stock->mlx_wdw);
	ft_free(stock);
	exit(EXIT_SUCCESS);
}

int			ft_save(char *str, t_list *stock)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		if (ft_cmp(&str[i], "-save") == 1)
		{
			stock->new_wdw = mlx_new_image(stock->mlx_co,
			stock->wdw_width, stock->wdw_height);
			stock->data_wdw = (int*)mlx_get_data_addr(stock->new_wdw,
			&stock->bit_pix_wdw, &stock->size_line_wdw, &stock->endian_wdw);
			ft_gen(stock);
			ft_end_save(stock);
		}
		else
		{
			ft_putstr("Error\nretry with -save\n");
			free(stock);
		}
	}
	return (0);
}
