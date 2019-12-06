/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:17:01 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/06 15:09:29 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

void	ft_adding_height(t_list *stock, int *i)
{
	stock->wdw_height *= 10;
	stock->wdw_height += stock->string[*i] - '0';
	*i += 1;
}

int		ft_search_wall(t_list *stock, int i)
{
	ft_open(stock);
	while (get_next_line(stock->fd, &stock->string))
	{
		if (i == 0)
		{
			if (stock->string[0] == 'N' && stock->string[1] == 'O')
			{
				return (1);
				close(stock->fd);
			}
		}
		if (i == 1)
		{
			if (stock->string[0] == 'S' && stock->string[1] == 'O')
			{
				return (1);
				close(stock->fd);
			}
		}
		if (ft_seach_wall_2(stock, i) == 1)
			return (1);
		ft_free(stock);
	}
	return (0);
}

int		ft_open(t_list *stock)
{
	if ((stock->fd = open(stock->file, O_RDONLY)) == -1)
		return (0);
	return (1);
}

int		ft_isnum(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_convert(char *str)
{
	int i;
	int color;
	int s;
	int rgb;

	s = 0;
	color = 0;
	if ((i = 1) == 1 && (str[0] == 'F' || str[0] == 'C'))
	{
		while (str[i] == ' ')
			i++;
		while (ft_isnum(str[i]) == 1 || str[i] == ' ')
		{
			if (ft_isnum(str[i]) == 1)
				color = color * 10 + str[i] - '0';
			i++;
			if (str[i] == ',' && ++s < 3)
				color = ft_rg(color, &s, &rgb, &i);
		}
		if (str[i] != '\0' && ft_isnum(str[i]) != 1)
			return (-1);
		if (s == 2 && color <= 255)
			return ((rgb << 8) | color);
	}
	return (-1);
}
