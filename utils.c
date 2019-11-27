/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:17:01 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/26 13:19:01 by mpouzol          ###   ########.fr       */
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
	if ((stock->fd = open("fil.cub", O_RDONLY)) == -1)
		return (-1);
	if (!(stock->string = malloc(sizeof(char))))
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
			if (str[i] == ',')
				i++;
		}
		if (str[i] != '\0' && ft_isnum(str[i]) != 1)
			return (-1);
		if (i <= 11)
			return (color);
	}
	return (-1);
}
