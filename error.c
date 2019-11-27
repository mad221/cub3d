/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:31:23 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/27 11:33:45 by mpouzol          ###   ########.fr       */
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

	if (number <= -8)
	{
		i = 6;
		while (++i < stock->map_height)
			free(stock->map[i]);
		free(stock->map);
	}
	i = -1;
	if (number < -3)
	{
		while (++i < 4)
			free(stock->mlx_wall[i]);
		free(stock->mlx_wall);
	}
	if (number < 0)
		free(stock->string);
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
		ft_putstr("Error\nInvalid File\n");
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
	return (ft_free_error(number, stock));
}
