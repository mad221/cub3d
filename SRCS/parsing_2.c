/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:43:09 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/01 16:56:55 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

void	ft_correct_resolution(t_list *stock)
{
	if (stock->wdw_height > 1440)
		stock->wdw_height = 1440;
	if (stock->wdw_width > 2560)
		stock->wdw_width = 2560;
}

int		ft_resolution(t_list *stock)
{
	int i;

	i = 0;
	if (stock->string[i] == 'R')
	{
		i++;
		while (stock->string[i] == ' ')
			i++;
		while (ft_isnum(stock->string[i]) == 1)
			stock->wdw_width = stock->wdw_width * 10 + stock->string[i++] - '0';
		while (stock->string[i] == ' ')
			i++;
		while (ft_isnum(stock->string[i]) == 1)
			ft_adding_height(stock, &i);
		if (stock->string[i] != '\0' &&
		ft_isnum(stock->string[i]) == 0 && ft_free(stock))
			return (0);
		ft_free(stock);
		return (1);
	}
	ft_free(stock);
	return (0);
}

int		ft_bg(char *str, int order)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 'N' && str[++i] == 'O' && order == 0)
		while (str[++i] == ' ')
			;
	if (str[i] == 'S' && str[++i] == 'O' && order == 1)
		while (str[++i] == ' ')
			;
	if (str[i] == 'W' && str[++i] == 'E' && order == 2)
		while (str[++i] == ' ')
			;
	if (str[i] == 'E' && str[++i] == 'A' && order == 3)
		while (str[++i] == ' ')
			;
	if (str[0] == 'S' && str[1] == ' ' && order == 4)
		while (str[++i] == ' ')
			;
	return (i++);
}

int		ft_seach_wall_2(t_list *stock, int i)
{
	if (i == 2)
	{
		if (stock->string[0] == 'W' && stock->string[1] == 'E')
		{
			return (1);
			close(stock->fd);
		}
	}
	if (i == 3)
	{
		if (stock->string[0] == 'E' && stock->string[1] == 'A')
		{
			return (1);
			close(stock->fd);
		}
	}
	return (0);
}

int		ft_len(char *str)
{
	int i;
	int s;

	s = 0;
	i = 0;
	while (str && str[i])
		if (str[i++] != ' ')
			s++;
	return (s);
}
