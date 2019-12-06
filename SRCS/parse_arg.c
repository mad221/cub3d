/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:10:48 by mpouzol           #+#    #+#             */
/*   Updated: 2019/12/06 12:10:01 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.h"
#include "get_next_line.h"

static int	ft_stop(t_list *stock)
{
	ft_putstr("Error\nFile Not Found\n");
	free(stock->file);
	free(stock);
	return (0);
}

int			ft_check_parse(t_list *stock)
{
	int i;

	i = 0;
	if (ft_open(stock) <= 0)
		return (ft_stop(stock));
	while (get_next_line(stock->fd, &stock->string) && stock->string[0] != 1)
	{
		if (stock->string[0] == 'R' || (stock->string[0] == 'N' &&
		stock->string[0] == 'O') || stock->string[0] == 'S' ||
		stock->string[0] == 'W' || stock->string[0] == 'E' ||
		stock->string[0] == 'F' || stock->string[0] == 'C')
			i++;
		ft_free(stock);
	}
	ft_free(stock);
	close(stock->fd);
	if (i != 7)
	{
		free(stock->file);
		free(stock);
		ft_putstr("Error\nWrong Argument Given In Config\n");
		return (0);
	}
	return (1);
}
