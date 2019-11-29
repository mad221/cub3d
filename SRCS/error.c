/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:31:23 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/29 19:28:38 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putchar(char c)
{
	write(2, &c, 1);
}

int		ft_free_error(int number, t_list *stock)
{
	int i;

	i = -1;
	while (++i < stock->map_height)
		free(stock->map[i]);
	free(stock->map);
	i = -1;
	printf("number = %d\n", number);
	if (number < -2)
	{
		while (++i < stock->nbr_texture)
		{
			free(stock->cast[i]);
			free(stock->mlx_wall[i]);
		}
		free(stock->mlx_wall[i]);
		free(stock->cast);
		free(stock->mlx_wall);
		free(stock->new_wdw);
		free(stock->data_wdw);
		mlx_destroy_window(stock->mlx_co, stock->mlx_wdw);
		free(stock->sprite);
		free(stock->sprite_data);
		free(stock->mlx_co);
	}
	close(stock->fd);
	free(stock->file);
	free(stock);
	return (0);
}

int		ft_free(t_list *stock)
{
	free(stock->string);
	return (1);
}

int		ft_message(int number, t_list *stock)
{
	if (number >= 1)
		return (number);
	if (number == -1)
		ft_putstr("Error\nFile Not Found\n");
	if (number == -2)
		ft_putstr("Error\nInvalid Format Resolution\n");
	if (number == -3)
		ft_putstr("Error\nTexture WALL Not Found\n");
	if (number == -4)
		ft_putstr("Error\nTexture Sprite Not Found\n");
	if (number == -5)
		ft_putstr("Error\nInvalid Format Color\n");
	if (number == -6)
		ft_putstr("Error\nInvalid Set Position\n");
	if (number == -7)
		ft_putstr("Error\nWrong Fence Set In Mapping\n");
	if (number == -8)
		ft_putstr("Error\nBad Sizing Map\n");
	if (number == -9)
		ft_putstr("Error\nBad Argument Given In Map\n");
	if (number == -10)
		ft_putstr("Error\nUnknow Player Position");
	stock->error = 12;
	return ((ft_free_error(number, stock)));
}
