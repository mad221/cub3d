/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:02:13 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/29 17:17:30 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

static int	ft_sprite(t_list *stock)
{
	while (get_next_line(stock->fd, &stock->string) && stock->string[0] != 'S'
	&& ft_free(stock))
		;
	if ((stock->sprite = mlx_xpm_file_to_image(stock->mlx_co,
	&stock->string[ft_bg(stock->string, 4)], &stock->sprite_width,
	&stock->sprite_height)) <= 0)
		return (0);
	if ((stock->sprite_data = (int*)mlx_get_data_addr((void*)stock->sprite,
	&stock->sprite_bpx, &stock->sprite_size_line,
	&stock->sprite_endian)) <= 0)
		return (0);
	ft_free(stock);
	return (1);
}

int			ft_map(t_list *stock)
{
	int line;
	int i;

	line = 0;
	i = 0;
	if (ft_search_map(stock, &i) == 0)
		return (0);
	if (!(stock->map = malloc(sizeof(int*) * i)))
		return (0);
	while (get_next_line(stock->fd, &stock->string) && stock->string[0] != '1')
		free(stock->string);
	while (--i > 0)
	{
		stock->map[line] = malloc(sizeof(int) * ft_len(stock->string));
		stock->lenstring = ft_conv(stock->map[line++], stock->string);
		ft_free(stock);
		get_next_line(stock->fd, &stock->string);
		stock->map_height = line;
		if (stock->lenstring != ft_len(stock->string) && i > 1)
		{
			printf("je pars d'ici \n");
			free(stock->string);
			return (-8);
		}
	}
	ft_free(stock);
	return (ft_init_pos(stock));
}

int			ft_check_map(t_list *stock)
{
	int i;
	int s;

	i = -1;
	while (++i < stock->map_height)
	{
		if (stock->map[i][0] != 1 || stock->map[i][stock->lenstring - 1] != 1)
			return (0);
		s = -1;
		while (++s < stock->lenstring)
			if (stock->map[0][s] != 1 ||
			stock->map[stock->map_height - 1][s] != 1)
				return (0);
	}
	return (1);
}

int			ft_parsing(t_list *stock)
{
	int			error;

	if (ft_open(stock) == 0)
		return (-1);
		printf("je suis la1 \n");
	if (ft_resolution(stock) == 0)
		return (-2);
		printf("je suis la 2\n");
	if (ft_texture(stock) == 0)
		return (-3);
		printf("je suis la 3\n");
	if (ft_sprite(stock) == 0)
		return (-4);
		printf("je suis la 4\n");
	if (ft_color(stock) == 0)
		return (-5);
		printf("je suis la 5\n");
	if ((error = ft_map(stock)) <= 0)
		return (error);
		printf("je suis la6\n");
	if (ft_check_map(stock) == 0)
		return (-7);
		printf("je suis la 7\n");
	return (1);
}
