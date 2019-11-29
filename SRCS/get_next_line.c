/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpouzol <mpouzol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:48:40 by mpouzol           #+#    #+#             */
/*   Updated: 2019/11/28 20:08:25 by mpouzol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_add_char(char **line, char c, int len)
{
	int			i;
	char		*str;

	if (!(str = malloc(sizeof(char) * len + 2)))
		return (0);
	i = 0;
	if (line)
		while (line[0][i])
		{
			str[i] = line[0][i];
			i++;
		}
	str[i] = c;
	str[i + 1] = '\0';
	free(*line);
	*line = str;
	return (1);
}

static void		ft_clean(char *line, char *buffer, int max_buff)
{
	buffer[max_buff] = '\0';
	line[0] = '\0';
}

static int		ft_read(int *i, int *ret, int fd, char *buffer)
{
	if (*i == 0)
		if ((*ret = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (*ret);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	static int	i = 0;
	static int	ret = 0;

	if (!(*line = malloc(sizeof(char))) || fd < 0 || BUFFER_SIZE < 0)
		return (-1);
	if (ft_read(&i, &ret, fd, buffer) < 0)
		return (-1);
	ft_clean(*line, buffer, ret);
	while (ret > 0)
	{
		if (buffer[i] == '\0')
		{
			i = 0;
			if ((ret = read(fd, buffer, BUFFER_SIZE)) <= 0)
				return (ret);
			buffer[ret] = '\0';
		}
		while (buffer[i] != '\n' && buffer[i])
			if (!(ft_add_char(line, buffer[i++], ft_strlen(*line))))
				return (-1);
		if ((i < ret || i == BUFFER_SIZE) && buffer[i] == '\n' && i++ >= 0)
			return (1);
	}
	return (0);
}
