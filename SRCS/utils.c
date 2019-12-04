/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:17:01 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/29 13:05:03 by mpouzol          ###   ########.fr       */
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

int		ft_gnl_pos(t_list *stock, char c1, char c2)
{
	while (get_next_line(stock->fd, &stock->string) && (stock->string[0] != c1
	|| stock->string[1] != c2))
		ft_free(stock);
	return (1);
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

int ft_rg(int color, int s, int *rgb, int *i)
{
	if (s == 1)
		*rgb = color;
  	if (s ==2)
	  *rgb = (*rgb << 8) | color;
	*i += 1;
  return (0);
}

int		ft_convert(char *str)
{
	int i;
	int color;
	int s;
	int rgb;

	s = 0;
	i = 0;
	color = 0;
	if (str[i] == 'F' || str[i] == 'C')
	{
		i++;
		while (str[i] == ' ')
			i++;
		while (ft_isnum(str[i]) == 1)
		{
			color = color * 10 + str[i] - '0';
			i++;
			if (str[i] == ',' && ++s < 3)
				color = ft_rg(color ,s , &rgb);
		}
		if (str[i] != '\0' && ft_isnum(str[i]) != 1)
			return (-1);
		if (i <= 11 && s == 2)
			return ((rgb << 8) | color);
	}
	return (-1);
}
